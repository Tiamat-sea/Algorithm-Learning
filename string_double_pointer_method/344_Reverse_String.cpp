/* ��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������
 * ��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
 */
#include <iostream>
#include <vector>
#include "vector_output.h"
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        auto left = s.begin();
        auto right = s.end() - 1;
        while (left < right) {
            swap(* left, * right);
            left++;
            right--;
        }
    }
};

int main() {
    vector<char> s {'h', 'e', 'l', 'l', 'o'};
    Solution solution;
    solution.reverseString(s);
    cout << s;
}