/**
* ����һ������ nums��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ����val��Ԫ�أ��������Ƴ���������³��ȡ�
* ��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣
* Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
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