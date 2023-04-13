/**
* ����һ���������� nums ���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] ���� i != j��i != k �� j != k ��
* ͬʱ������ nums[i] + nums[j] + nums[k] == 0 ����
* �㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣
* ע�⣺���в����԰����ظ�����Ԫ�顣
*/
#include <iostream>
#include <vector>
#include "vector_output.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) return result;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else{
                    result.push_back(vector<int> {nums[i], nums[left], nums[right]});
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums {-1, 0, 1, 2, -1, -4};
    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);
    showTwoVector(result);
}