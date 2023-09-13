#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        size_t len1 = nums1.size();
        size_t len2 = nums2.size();
        if ((len1 + len2) % 2 == 0) {
            double r1 = (double) findKth(nums1, 0, len1, nums2, 0, len2, (len1 + len2) / 2);
            double r2 = (double) findKth(nums1, 0, len1, nums2, 0, len2, (len1 + len2) / 2 + 1);
            return (r1 + r2) / 2.0;
        } else {
            return findKth(nums1, 0, len1, nums2, 0, len2, (len1 + len2 + 1) / 2);
        }
    }

private:
    int findKth(
        vector<int> &nums1, size_t begin1, size_t end1,
        vector<int> &nums2, size_t begin2, size_t end2,
        size_t k
    ) {
        size_t n = end1 - begin1;
        size_t m = end2 - begin2;
        if (n <= 0) {
            return nums2[begin2 + k - 1];
        }
        if (m <= 0) {
            return nums1[begin1 + k - 1];
        }
        if (k == 1) {
            return nums1[begin1] < nums2[begin2] ? nums1[begin1] : nums2[begin2];
        }
        size_t mid1 = (begin1 + end1) / 2;
        size_t mid2 = (begin2 + end2) / 2;
        if (nums1[mid1] <= nums2[mid2]) {
            if (n / 2 + m / 2 + 1 >= k) {
                return findKth(nums1, begin1, end1, nums2, begin2, mid2, k);
            } else {
                return findKth(nums1, mid1 + 1, end1, nums2, begin2, end2, k - n / 2 - 1);
            }

        } else {
            if (n / 2 + m / 2 + 1 >= k) {
                return findKth(nums1, begin1, mid1, nums2, begin2, end2, k);
            } else {
                return findKth(nums1, begin1, end1, nums2, mid2 + 1, end2, k - m / 2 - 1);
            }

        }
    }
};

void print_nums(vector<int> &nums)
{
    cout << "[";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        cout << *it;
        if ((it + 1) != nums.end()) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main()
{
    vector<pair<vector<int>, vector<int>>> params{
        {{1, 3}, {2}},
        {{1, 2}, {3, 4}},
    };

    Solution s;
    for (auto it = params.begin(); it != params.end(); it++) {
        cout << endl;
        auto nums1 = it->first;
        auto nums2 = it->second;

        cout << "Input:" << endl;
        cout << " nums1 = ";
        print_nums(nums1);
        cout << endl;
        cout << " nums2 = ";
        print_nums(nums2);
        cout << endl;

        auto mid = s.findMedianSortedArrays(nums1, nums2);
        cout << "Output: " << mid << endl;
    }

    return 0;
}
