//
// Created by 16664 on 2023/3/28 ���� 09:30.
//
/* �����ĸ��������� nums1��nums2��nums3 �� nums4 �����鳤�ȶ��� n ����������ж��ٸ�Ԫ�� (i, j, k, l) �����㣺
 * 0 <= i, j, k, l < n
 * nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum12_map;
        for (int num1 : nums1) {
            for (int num2 : nums2) {
                sum12_map[num1 + num2]++;
            }
        }
        int count = 0;
        for (int num3 : nums3) {
            for (int num4 :nums4) {
                if (sum12_map.find(0 - num3 - num4) != sum12_map.end()) {
                    count += sum12_map[0 - num3 - num4];
                }
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};
    Solution solution;

    cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << endl;
}