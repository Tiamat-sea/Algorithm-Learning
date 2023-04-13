//
// Created by 16664 on 2023/3/28 下午 02:10.
//
/* 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 */
#include <iostream>
#include <unordered_set>
#include <vector>
#include "vector_output.h"
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (nums1_set.find(num) != nums1_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

class Solution2 {
public:
    static vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result_set;
        int hash[1001] = {0};
        for (int num : nums1) {
            hash[num] = 1;
        }
        for (int num : nums2) {
            if (hash[num] == 1 && find(result_set.begin(), result_set.end(), num) == result_set.end()) {
                result_set.insert(result_set.end(), num);
            }
        }
        return result_set;
    }
};

int main() {
    vector<int> nums1 {4, 9, 5}, nums2 {9, 4, 9, 8, 4};
//    vector<int> nums1 {1, 2, 2, 1}, nums2 {2, 2};
    Solution solution;
//    Solution2 solution2;
    vector<int> res = Solution2::intersection(nums1, nums2);

    cout << res;
}