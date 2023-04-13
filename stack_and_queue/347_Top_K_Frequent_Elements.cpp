/**
* ����һ���������� nums ��һ������ k �����㷵�����г���Ƶ��ǰ k �ߵ�Ԫ�ء�����԰� ����˳�� ���ش𰸡�
*/
#include <iostream>
#include <vector>
#include "vector_output.h"
using namespace std;

class Solution {
public:
    class MyComparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num : nums) map[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComparison> pri_que;
        for (auto it = map.begin(); it != map.end(); ++it) {
            pri_que.push(*it);
            if (pri_que.size() > k) pri_que.pop();
        }
        vector<int> result(k);
        for (int i = k - 1; i >= 0; --i) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

int main() {
    vector<int> nums {1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution solution;

    vector<int> result = solution.topKFrequent(nums, k);
    cout << result << endl;
}