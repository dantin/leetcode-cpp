#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>

void print_nums(std::vector<int> nums)
{
    std::cout << "[";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        std::cout << *it;
        if ((it + 1) != nums.end()) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

void print_strs(std::vector<std::string> strs)
{
    std::cout << "[";
    for (auto it = strs.begin(); it != strs.end(); ++it) {
        std::cout << "\"" << *it << "\"";
        if ((it + 1) != strs.end()) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

void print_nums_array(std::vector<std::vector<int>> nums)
{
    std::cout << "[" << std::endl;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        std::cout << "   ";
        print_nums(*it);
        if ((it + 1) != nums.end()) {
            std::cout << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "]";
}

void print_board(std::vector<std::vector<char>> &board)
{
    std::cout << "[";
    for (auto rit = board.begin(); rit != board.end(); ++rit) {
        if (rit != board.begin()) {
            std::cout << std::endl << ",";
        }
        std::cout << "[";
        for (auto cit = rit->begin(); cit != rit->end(); ++cit) {
            if (cit != rit->begin()) {
                std::cout << ", ";
            }
            std::cout << "\"" << *cit << "\"";
        }
        std::cout << "]";
    }
    std::cout << "]" << std::endl;
}

#endif
