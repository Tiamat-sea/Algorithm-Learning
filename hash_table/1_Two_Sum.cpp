//
// Created by 16664 on 2023/3/28 下午 08:54.
//
/* 给定一个整数数组 nums和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include "vector_output.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = nums_map.find(target - nums[i]);
            if (iter != nums_map.end()) {
                return {iter->second, i};
            }
            else {
                nums_map.insert(pair<int, int> (nums[i], i));
            }
        }
        return {};
    }
};


int main() {
    vector<int> nums {2, 7, 11, 15};
    int target = 9;
    Solution solution;

    vector<int> res = solution.twoSum(nums, target);
    cout << res;
}