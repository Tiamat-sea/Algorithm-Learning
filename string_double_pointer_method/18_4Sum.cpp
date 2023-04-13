/**
* ����һ���� n ��������ɵ�����nums ����һ��Ŀ��ֵ target �������ҳ���������������ȫ�������Ҳ��ظ�����
* Ԫ��[nums[a], nums[b], nums[c], nums[d]]����������Ԫ��Ԫ��һһ��Ӧ������Ϊ������Ԫ���ظ�����
* 0 <= a, b, c, d< n
* a��b��c �� d ������ͬ
* nums[a] + nums[b] + nums[c] + nums[d] == target
* ����԰� ����˳�� ���ش� ��
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