/*给定一个含有n个正整数的数组和一个正整数 target。
 *找出该数组中满足其和 ≥ target 的长度最小的 连续子数组[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX;//结果
        int i = 0;//滑动窗口起始位置
        int subLength = 0;//滑动窗口的长度
        int sum = 0;//滑动窗口元素和

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                subLength = j - i + 1;
                res = res < subLength ? res : subLength;
                sum -= nums[i++];
            }
        }
        return res == INT32_MAX ? 0 : res;
    }
};

int main() {
    int target = 7, nums[] = {2, 3, 1, 2, 4, 3};

    vector<int> data(begin(nums), end(nums));
    Solution solution;

    cout << solution.minSubArrayLen(target, data) << endl;
}