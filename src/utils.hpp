#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <iterator>
#include <string>
#include <type_traits>
#include <vector>

/**
 * @file utils.hpp
 * @brief Common utility functions for LeetCode solutions
 *
 * This header contains utility functions used across multiple LeetCode solution files
 * to avoid code duplication and maintain consistency.
 */

namespace utils {

/**
 * Print a vector with proper formatting
 * Handles both primitive types and strings with appropriate quoting
 */
template <typename T>
void print_vector(const std::vector<T>& v)
{
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if constexpr (std::is_same_v<T, std::string>) {
            std::cout << "'" << v[i] << "'";
        } else {
            std::cout << v[i];
        }
        if (i != v.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

/**
 * Print any container that supports iterators
 * More generic version for different container types
 */
template <typename Container>
void print_container(const Container& container)
{
    std::cout << "[";
    for (auto it = container.begin(); it != container.end(); ++it) {
        if constexpr (std::is_same_v<typename Container::value_type, std::string>) {
            std::cout << "'" << *it << "'";
        } else {
            std::cout << *it;
        }
        if (std::next(it) != container.end()) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

// Backward compatibility alias
template <typename T>
void print_array(const std::vector<T>& v)
{
    print_vector(v);
}

}  // namespace utils

#endif  // UTILS_HPP