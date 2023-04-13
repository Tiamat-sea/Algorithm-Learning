/**
 * 给你两个字符串haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
 * 如果needle 不是 haystack 的一部分，则返回 -1 。
 */
#include <iostream>

using namespace std;

/**前缀表减一的实现*/
class Solution {
public:
    void getNext(int *next, const string &s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); ++i) {
            while (j >= 0 && s[i] != s[j + 1]) {//前后缀不同
                j = next[j];//向前回退
            }
            if (s[i] == s[j + 1]) {//找到相同的前后缀
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
            while (j > 0 && haystack[i] != needle[j + 1]) {//不匹配
                j = next[j];//寻找之前匹配的位置
            }
            if (haystack[i] == needle[j + 1]) {//匹配，i、j同同时向后移动
                j++;
            }
            if (j == needle.size() - 1) {//文本串里出现了模式串
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

/**前缀表不减一*/
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