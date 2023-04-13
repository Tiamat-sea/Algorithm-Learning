/**
 * 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
 * */

#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1);
        if (t.find(s) != string::npos) return true;
        return false;
    }
};

class Solution2 {
public:
    void getNext(int *next, const string &s) {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j]) j = next[j - 1];
            if (s[i] == s[j]) j++;
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) return false;
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0) return true;
        return false;
    }
};

int main() {
    string s = "abac";
    Solution2 solution;

    cout << solution.repeatedSubstringPattern(s) << endl;
}