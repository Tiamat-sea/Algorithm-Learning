/**
* 给你一个数组 nums和一个值 val，你需要 原地 移除所有数值等于val的元素，并返回移除后数组的新长度。
* 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
* 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != val) nums[slow++] = nums[fast];
            fast++;
        }
        return slow;
    }
};

int main() {
    vector<int> nums {3, 2, 2, 3};
    int val = 3;
    Solution solution;
    int newLen = solution.removeElement(nums, val);
    cout << newLen << endl;
    for (int i = 0; i < newLen; ++i) {
        cout << nums[i] << "  ";
    }
    cout << endl;
}