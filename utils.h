#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>

template<typename T>
void print_array(T const &xs)
{
    std::cout << "[";
    for (auto it = xs.begin(); it != xs.end(); ++it) {
        std::cout << *it;
        if ((it + 1) != xs.end()) {
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
        print_array(*it);
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
