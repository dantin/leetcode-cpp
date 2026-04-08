import argparse
import configparser
import json
import logging
import random
import time
from dataclasses import dataclass, field
from pathlib import Path

import markdownify
import requests

logger = logging.getLogger(__name__)


BASE_URL = "https://leetcode.cn"
CACHE_FILE = Path(__file__).parent / "problems.json"


@dataclass
class Problem:
    pid: int = field(default=0)
    title: str = field(default="")
    name: str = field(default="")
    url: str = field(default="")
    difficulty: int = field(default=0)
    description: str = field(default="")
    solution: str = field(default="")
    status: str = field(default="")


def load_cookies(config_path: Path) -> dict[str, str]:
    """
    load_cookies loads the cookies from config.ini
    """
    config = configparser.ConfigParser()
    config.optionxform = str  # Preserve case for cookie keys
    config.read(config_path)
    if "Cookies" in config:
        return dict(config["Cookies"])
    return {}


def fetch_all_problems(cookies: dict[str, str]) -> dict:
    """
    Fetches all problems from LeetCode API, using a local cache to avoid HTTP request limits.
    """
    if CACHE_FILE.exists():
        logger.debug("Fetching problems from cache...")
        with open(CACHE_FILE, "r", encoding="utf-8") as f:
            return json.load(f)

    logger.debug("Cache not found. Fetching problems from LeetCode API...")
    url = f"{BASE_URL}/api/problems/all/"

    headers = {
        "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.15; rv:149.0) Gecko/20100101 Firefox/149.0",
        "Accept": "application/json, text/javascript, */*; q=0.01",
        "Accept-Language": "en-US,en;q=0.9",
        "Accept-Encoding": "gzip, deflate",
        "Connection": "keep-alive",
        "Upgrade-Insecure-Requests": "1",
        "Sec-Fetch-Dest": "document",
        "Sec-Fetch-Mode": "navigate",
        "Sec-Fetch-Site": "none",
        "Priority": "u=0, i",
    }

    response = requests.get(url, cookies=cookies, headers=headers)
    response.raise_for_status()

    data = response.json()

    # Cache the result to avoid rate limits
    with open(CACHE_FILE, "w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=2)

    return data


def scrape_problems(cookies: dict[str, str]):
    """
    scrape_problems extracts the problem list using the LeetCode API response
    """
    data = fetch_all_problems(cookies)
    problems = []

    stat_status_pairs = data.get("stat_status_pairs", [])
    for item in stat_status_pairs:
        stat = item.get("stat", {})
        # Note: frontend_question_id can be a string for some newer/LCP problems,
        # but is usually castable to int if it's purely a number.
        raw_pid = stat.get("frontend_question_id", 0)
        title = stat.get("question__title", "")
        slug = stat.get("question__title_slug", "")
        difficulty = item.get("difficulty", {}).get("level", 0)
        status = item.get("status", "")

        try:
            pid = int(raw_pid)
        except ValueError:
            # Keep string representation for problem IDs like "LCP 82" if needed,
            # or skip if only integer PIDs are expected. For now, skip non-ints.
            continue

        href = f"/problems/{slug}/"
        problems.append(
            Problem(
                pid=pid,
                title=title,
                name=slug,
                url=href,
                difficulty=difficulty,
                status=status,
            )
        )

    # Sort problems by pid since the API returns them unordered or by some other logic
    problems.sort(key=lambda p: p.pid)

    return problems


def fetch_problem_detail(problem: Problem, cookies: dict[str, str]) -> Problem:
    """
    Fetches detailed information for a specific problem using the LeetCode GraphQL API.
    """
    url = f"{BASE_URL}/graphql/"

    headers = {
        "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.15; rv:149.0) Gecko/20100101 Firefox/149.0",
        "Accept": "application/json, text/javascript, */*; q=0.01",
        "Accept-Language": "en-US,en;q=0.9",
        "Accept-Encoding": "gzip, deflate",
        "Connection": "keep-alive",
        "Content-Type": "application/json",
        "Origin": BASE_URL,
        "Referer": f"{BASE_URL}/problems/{problem.name}/",
    }

    query = """
    query getQuestionDetail($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        content
        stats
        likes
        dislikes
        codeDefinition
        sampleTestCase
        enableRunCode
        metaData
        translatedContent
      }
    }
    """

    payload = {
        "query": query,
        "variables": {"titleSlug": problem.name},
        "operationName": "getQuestionDetail",
    }

    logger.debug(f"Fetching details for problem: {problem.name}")
    response = requests.post(url, json=payload, cookies=cookies, headers=headers)
    response.raise_for_status()

    data = response.json()
    question_data = data.get("data", {}).get("question", {})

    # 1 & 2. Generate Markdown document from HTML content and set to Problem.description
    content_html = question_data.get("content", "")
    if content_html:
        problem.description = markdownify.markdownify(content_html)

    # 3. Extract codeDefinition for "cpp" and set to Problem.solution
    code_definition_str = question_data.get("codeDefinition", "[]")
    try:
        code_defs = json.loads(code_definition_str)
        for cdef in code_defs:
            if cdef.get("value") == "cpp" and cdef.get("text") == "C++":
                problem.solution = cdef.get("defaultCode", "")
                break
    except json.JSONDecodeError:
        logger.warning(f"Failed to parse codeDefinition for problem: {problem.name}")

    return problem


def persist_problem(problem: Problem, root_dir: Path):
    """
    Persists the problem details to the local filesystem.
    """
    src_dir = root_dir / "src" / problem.name
    src_dir.mkdir(parents=True, exist_ok=True)

    problem_md = src_dir / "problem.md"
    problem_md_content = f"# {problem.title}\n\n{problem.description}\n"
    problem_md.write_text(problem_md_content, encoding="utf-8")

    solution_hpp = src_dir / "solution.hpp"
    solution_hpp_content = f"""#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <bits/stdc++.h>

{problem.solution}

#endif
"""
    solution_hpp.write_text(solution_hpp_content, encoding="utf-8")


def generate_problemset(problems: list[Problem], root_dir: Path):
    """
    Generates a PROBLEMSET.md file containing a table of all problems.
    """
    lines = [
        "# LeetCode Problem Set",
        "",
        "| ID | Name | Difficulty | Status | Solution |",
        "|---|---|---|---|---|",
    ]
    for p in problems:
        if p.status != "ac":
            continue
        name_link = f"[{p.title}](src/{p.name}/problem.md)"
        sol_link = f"[solution](src/{p.name}/solution.hpp)"
        lines.append(
            f"| {p.pid} | {name_link} | {p.difficulty} | {p.status} | {sol_link} |"
        )

    problemset_md = root_dir / "PROBLEMSET.md"
    problemset_md.write_text("\n".join(lines) + "\n", encoding="utf-8")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Sync LeetCode Problem Set")
    parser.add_argument(
        "--log-level",
        default="INFO",
        choices=["DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"],
        help="Set the logging level (default: INFO)",
    )

    subparsers = parser.add_subparsers(dest="command", required=True)

    fetch_parser = subparsers.add_parser(
        "fetch", help="Fetch and persist a specific problem"
    )
    fetch_parser.add_argument(
        "problem_id", type=int, help="The ID of the problem to fetch"
    )

    problems_parser = subparsers.add_parser(
        "problems", help="Retrieve all problems and update PROBLEMSET.md"
    )

    args = parser.parse_args()

    logging.basicConfig(
        level=getattr(logging, args.log_level),
        format="%(asctime)s - %(levelname)s - %(message)s",
    )

    cfg_path = Path(__file__).parent / "config.ini"
    if not cfg_path.exists():
        raise FileNotFoundError(f"Config file not found at {cfg_path}")

    cookies = load_cookies(cfg_path)
    if not cookies:
        logger.error("No cookies found in config.ini")
        exit(1)

    problems = scrape_problems(cookies)
    root_dir = Path(__file__).parent

    if args.command == "fetch":
        target_problem = next((p for p in problems if p.pid == args.problem_id), None)
        if not target_problem:
            logger.error(f"Problem with ID {args.problem_id} not found.")
            exit(1)

        time.sleep(random.randint(1, 3))
        logger.info(f"Fetching problem: {target_problem.title} ({target_problem.pid})")
        target_problem = fetch_problem_detail(target_problem, cookies)
        persist_problem(target_problem, root_dir)
        logger.info(f"Successfully fetched and persisted problem {target_problem.pid}.")

    elif args.command == "problems":
        logger.info(f"Successfully retrieved {len(problems)} problems.")
        generate_problemset(problems, root_dir)
        logger.info("Successfully generated PROBLEMSET.md.")
