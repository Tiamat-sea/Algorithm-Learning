/**�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β�����붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����磬�����ַ���"abcdefg"������2����
 * ��������������ת��λ�õ��Ľ��"cdefgab"��
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