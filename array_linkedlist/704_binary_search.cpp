/*给定一个n个元素有序的（升序）整型数组nums 和一个目标值target ，写一个函数搜索nums中的 target，如果目标值存在返回下标，否则返回 -1。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size(), middle;
        while (left < right) {
            middle = (left + right) / 2;
            if (nums[middle] > target) {
                right = middle;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                return middle;
            }
        }
        return -1;
    }
};

int main() {
    int nums[] = {-1,0,3,5,9,12}, target = 2;

    vector<int> data(begin(nums), end(nums));

    Solution solution;
    cout << solution.search(data, target) << endl;
}
