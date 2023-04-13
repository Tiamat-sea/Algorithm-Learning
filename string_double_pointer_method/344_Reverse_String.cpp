/* 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
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