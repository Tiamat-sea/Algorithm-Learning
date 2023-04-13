/**字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该
 * 函数将返回左旋转两位得到的结果"cdefgab"。
 */
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string result = s;
        for (int i = 0; i < s.size(); ++i) {
            result[i] = s[(i + n) % s.size()];
        }
        return result;
    }
};

class Solution2 {
public:
    void reverse(string& s, int start, int end) {
        for (; start < end; ++start, --end) {
            swap(s[start], s[end]);
        }
    }

    string reverseLeftWords(string s, int n) {
        reverse(s, 0, n - 1);
        reverse(s, n, s.size() - 1);
        reverse(s, 0, s.size() - 1);
        return s;
    }
};

class Solution3 {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    string s = "abcdefg";
    int k = 2;
    Solution3 solution;
    cout << solution.reverseLeftWords(s, k) << endl;
}