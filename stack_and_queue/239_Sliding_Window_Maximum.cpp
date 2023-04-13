/**
 * 给你一个整数数组 nums，有一个大小为k的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k个数字。滑动窗口每次只向右移动一位。
 * 返回 滑动窗口中的最大值 。
*/
#include <iostream>
#include <deque>
#include <vector>
#include "vector_output.h"
using namespace std;

class Solution {
private:
    class MyQueue {
    public:
        deque<int> que;

        void pop(int value) {
            if (!que.empty() && que.front() == value) que.pop_front();
        }

        void push(int value) {
            while (!que.empty() && que.back() < value) que.pop_back();
            que.push_back(value);
        }

        int front() {
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; ++i) que.push(nums[i]);
        result.push_back(que.front());
        for (int i = k; i < nums.size(); ++i) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};

int main() {
    vector<int> nums {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution solution;

    vector<int> result = solution.maxSlidingWindow(nums, k);
    cout << result << endl;
}