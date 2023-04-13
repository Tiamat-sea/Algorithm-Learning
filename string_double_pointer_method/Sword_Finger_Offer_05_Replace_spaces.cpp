/* 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 */
#include <iostream>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int oldSize = s.size();
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') count++;
        }
        s.resize(s.size() + count * 2);
        int newSize = s.size();
        for (int i = newSize - 1, j = oldSize - 1; j < i; --i, --j) {
            if (s[j] != ' ') s[i] = s[j];
            else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};

int main() {
    string s = "We are happy.";
    Solution solution;
    cout << solution.replaceSpace(s) << endl;
}