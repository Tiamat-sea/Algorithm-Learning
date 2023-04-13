/**
 * ���������ַ���haystack �� needle �������� haystack �ַ������ҳ� needle �ַ����ĵ�һ��ƥ������±꣨�±�� 0 ��ʼ����
 * ���needle ���� haystack ��һ���֣��򷵻� -1 ��
 */
#include <iostream>

using namespace std;

/**ǰ׺���һ��ʵ��*/
class Solution {
public:
    void getNext(int *next, const string &s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); ++i) {
            while (j >= 0 && s[i] != s[j + 1]) {//ǰ��׺��ͬ
                j = next[j];//��ǰ����
            }
            if (s[i] == s[j + 1]) {//�ҵ���ͬ��ǰ��׺
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int next[needle.size()];
        getNext(next, needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); ++i) {
            while (j > 0 && haystack[i] != needle[j + 1]) {//��ƥ��
                j = next[j];//Ѱ��֮ǰƥ���λ��
            }
            if (haystack[i] == needle[j + 1]) {//ƥ�䣬i��jͬͬʱ����ƶ�
                j++;
            }
            if (j == needle.size() - 1) {//�ı����������ģʽ��
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

/**ǰ׺����һ*/
class Solution2 {
public:
    void getNext(int *next, const string &s) {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

int main() {
    string haystack = "leetcode", needle = "leeto";
//    string haystack = "sadbutsad", needle = "sad";
    Solution2 solution;

    cout << solution.strStr(haystack, needle) << endl;
}