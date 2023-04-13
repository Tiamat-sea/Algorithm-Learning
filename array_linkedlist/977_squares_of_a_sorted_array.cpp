/*给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 */

#include <iostream>
#include <vector>
#include "vector_output.h"
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int k = nums.size() - 1;

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                res[k--] = nums[right] * nums[right];
                right--;
            }
            else {
                res[k--] = nums[left] * nums[left];
                left++;
            }
        }
        return res;
    }
};

int main() {
    int nums[] = {-4, -1, 0, 3, 10};

    vector<int> data(begin(nums), end(nums));
    Solution solution;

    vector<int> res(data.size());
    res = solution.sortedSquares(data);

    cout << res;
}