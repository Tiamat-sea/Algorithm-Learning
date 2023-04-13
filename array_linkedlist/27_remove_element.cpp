/*给你一个数组 nums和一个值 val，你需要 原地 移除所有数值等于val的元素，并返回移除后数组的新长度。
 *不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
 *元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size(), tmp;
        while (i != j) {
            if (nums[i] == val) {
                if (nums[j - 1] != val) {
                    tmp = nums[i];
                    nums[i] = nums[j - 1];
                    nums[j - 1] = tmp;
                    i++;
                    j--;
                }
                if (nums[j - 1] == val) {
                    j--;
                }
            }
            else {
                i++;
            }
        }
        return j;
    }
};

class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main() {
    int nums[] = {3,2,2,3}, val = 3;

    vector<int> data(begin(nums), end(nums));
    Solution solution;
    Solution2 solution2;
    cout << solution2.removeElement(data, val) <<endl;
}