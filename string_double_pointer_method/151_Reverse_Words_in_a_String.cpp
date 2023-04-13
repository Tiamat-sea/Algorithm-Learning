/* ����һ���ַ��� s �����㷴ת�ַ����� ���� ��˳��
 * ���� ���ɷǿո��ַ���ɵ��ַ�����s ��ʹ������һ���ո��ַ����е� ���� �ָ�����
 * ���� ���� ˳��ߵ��� ���� ֮���õ����ո����ӵĽ���ַ�����
 * ע�⣺�����ַ��� s�п��ܻ����ǰ���ո�β��ո���ߵ��ʼ�Ķ���ո񡣷��صĽ���ַ����У����ʼ�Ӧ�����õ����ո�ָ����Ҳ������κζ���Ŀո�
 */
#include <iostream>
using namespace std;

class Solution {
public:
    void removeExtraSpaces(string& s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); ++fast) {
            if (s[fast] != ' ') {
                if (slow != 0) s[slow++] = ' ';
                while (fast < s.size() && s[fast] != ' ') s[slow++] = s[fast++];
            }
        }
        s.resize(slow);
    }

    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int end = 0; end <= s.size(); ++end) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s, start, end - 1);
                start = end + 1;
            }
        }
        return s;
    }
};

int main() {
    string s = "the sky is blue";
    Solution solution;
    cout << solution.reverseWords(s) << endl;
}