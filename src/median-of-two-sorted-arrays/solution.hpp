#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <bits/stdc++.h>

class Solution {
   public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        size_t len1 = nums1.size();
        size_t len2 = nums2.size();
        if ((len1 + len2) % 2 == 0) {
            double r1 = (double)findKth(nums1, 0, len1, nums2, 0, len2, (len1 + len2) / 2);
            double r2 = (double)findKth(nums1, 0, len1, nums2, 0, len2, (len1 + len2) / 2 + 1);
            return (r1 + r2) / 2.0;
        } else {
            return findKth(nums1, 0, len1, nums2, 0, len2, (len1 + len2 + 1) / 2);
        }
    }

   private:
    int findKth(std::vector<int>& nums1, size_t begin1, size_t end1, std::vector<int>& nums2,
                size_t begin2, size_t end2, size_t k)
    {
        size_t n = end1 - begin1;
        size_t m = end2 - begin2;

        // Base cases: if one array is empty, return from the other
        if (n == 0) {
            return nums2[begin2 + k - 1];
        }
        if (m == 0) {
            return nums1[begin1 + k - 1];
        }
        if (k == 1) {
            return std::min(nums1[begin1], nums2[begin2]);
        }

        // Try to discard k/2 elements from one of the arrays
        // Make sure we don't go out of bounds
        size_t i = begin1 + std::min(k / 2, n) - 1;
        size_t j = begin2 + std::min(k / 2, m) - 1;

        if (nums1[i] <= nums2[j]) {
            // Discard the first min(k/2, n) elements from nums1
            size_t discarded = i - begin1 + 1;
            return findKth(nums1, i + 1, end1, nums2, begin2, end2, k - discarded);
        } else {
            // Discard the first min(k/2, m) elements from nums2
            size_t discarded = j - begin2 + 1;
            return findKth(nums1, begin1, end1, nums2, j + 1, end2, k - discarded);
        }
    }
};

template <typename T>
void print_array(T const& xs)
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

#endif
