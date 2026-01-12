# Regular Expression Matching Algorithm

## Algorithm Overview

The function uses recursion with two cases: when the next pattern character is `*`, and when it isn't.

## Step-by-Step Breakdown

### 1. Base Case (lines 10-12)

```cpp
if (*p == '\0') {
  return *s == '\0';
}
```

If the pattern is exhausted, return true only if the string is also exhausted.

### 2. Non-`*` Case (lines 13-18)

```cpp
if (*(p + 1) != '*') {
  if (*s != '\0' && (*p == *s || *p == '.')) {
    return isMatch(s + 1, p + 1);
  } else {
    return false;
  }
}
```

If the next character is not `*`, match exactly one character:

- Ensure the string is not empty.
- Check if `*p == *s` or `*p == '.'`.
- If it matches, recurse on the rest of both strings.
- Otherwise, return false.

### 3. `*` Case (lines 19-27)

```cpp
else {
  while (*p == *s || (*p == '.' && *s != '\0')) {
    if (isMatch(s, p + 2)) {
      return true;
    }
    s++;
  }
  return isMatch(s, p + 2);
}
```

When the next character is `*`, try matching zero or more occurrences:

- The while loop tries one or more matches:
  - If the current character matches (`*p == *s` or `*p == '.'`), try matching the rest with `p + 2` (skip the `*` pattern).
  - If that succeeds, return true.
  - Otherwise, consume one character from `s` and try again.
- After the loop, try matching zero occurrences by skipping the `*` pattern: `isMatch(s, p + 2)`.

## Example Traces

### Example 1: `s = "aa"`, `p = "a"`

- Pattern exhausted: `*p == '\0'` → `*s == 'a'` → return false.

### Example 2: `s = "aa"`, `p = "a*"`

- `*(p+1) == '*'` → enter `*` case.
- `*p == 'a'`, `*s == 'a'` → match.
- Try `isMatch("aa", "")` → false.
- `s++` → `s = "a"`.
- `*p == 'a'`, `*s == 'a'` → match.
- Try `isMatch("a", "")` → false.
- `s++` → `s = ""`.
- Loop exits (no match).
- Try `isMatch("", "")` → true. Return true.

### Example 3: `s = "ab"`, `p = ".*"`

- `*(p+1) == '*'` → enter `*` case.
- `*p == '.'`, `*s == 'a'` → match.
- Try `isMatch("ab", "")` → false.
- `s++` → `s = "b"`.
- `*p == '.'`, `*s == 'b'` → match.
- Try `isMatch("b", "")` → false.
- `s++` → `s = ""`.
- Loop exits.
- Try `isMatch("", "")` → true. Return true.

### Example 4: `s = "aab"`, `p = "c*a*b"`

- `*(p+1) == '*'` → enter `*` case for `c*`.
- `*p == 'c'`, `*s == 'a'` → no match, loop skipped.
- Try `isMatch("aab", "a*b")` (zero `c`s).
- Continue with `a*` and `b` similarly.

## Key Insights

- **Greedy matching**: the `*` case tries one or more matches first, then falls back to zero.
- **Backtracking**: if a path fails, the recursion explores alternatives.
- **Two strategies for `*`**:
  - Match one character and recurse (inside the while loop).
  - Match zero characters by skipping the `*` pattern (after the loop).

## Time Complexity

- Worst case: O(2^(m+n)) where m and n are the lengths of s and p, due to backtracking.
- Can be optimized with memoization to O(m×n).

## Space Complexity

- O(m+n) due to the recursion stack.

This approach handles the matching rules recursively with backtracking.
