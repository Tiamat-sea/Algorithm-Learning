/**
* 给你一个由 n 个整数组成的数组nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四
* 元组[nums[a], nums[b], nums[c], nums[d]]（若两个四元组元素一一对应，则认为两个四元组重复）：
* 0 <= a, b, c, d< n
* a、b、c 和 d 互不相同
* nums[a] + nums[b] + nums[c] + nums[d] == target
* 你可以按 任意顺序 返回答案 。
*/
#include <iostream>
#include <vector>
#include "vector_output.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > target && nums[i] >= 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) break;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
                    else {
                        result.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution solution;

    showTwoVector(solution.fourSum(nums, target));
}