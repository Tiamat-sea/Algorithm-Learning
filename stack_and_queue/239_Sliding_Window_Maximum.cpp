/**
 * ����һ���������� nums����һ����СΪk�Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k�����֡���������ÿ��ֻ�����ƶ�һλ��
 * ���� ���������е����ֵ ��
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