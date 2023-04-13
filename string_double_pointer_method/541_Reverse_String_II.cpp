/* ����һ���ַ��� s ��һ������ k�����ַ�����ͷ����ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ���
 * ���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
 * ���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
 */
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            if (i + k < s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

class Solution2 {
public:
    void reverse(string &s, int start, int end) {
        for (; start < end; start++, end--) {
            swap(s[start], s[end]);
        }
    }

    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            if (i + k <= s.size()) {
                reverse(s, i, i + k - 1);
            }
            else reverse(s, i, s.size() - 1);
        }
        return s;
    }
};

class Solution3 {
public:
    string reverseStr(string s, int k) {
        int pos = 0;
        while (pos < s.size()) {
            if (pos + k < s.size()) reverse(s.begin() + pos, s.begin() + pos + k);
            else reverse(s.begin() + pos, s.end());
            pos += 2 * k;
        }
        return s;
    }
};

int main() {
    string s = "abcdefg", res = "bacdfeg";
    int k = 2;
    Solution3 solution;
    cout << solution.reverseStr(s, k) << endl;

}