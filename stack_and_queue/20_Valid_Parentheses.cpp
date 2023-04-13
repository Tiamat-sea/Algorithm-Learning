/**
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']'的字符串 s ，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
*/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            else if (s[i] == '(') st.push(')');
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop();
        }
        return st.empty();
    }
};

int main() {
    string s = "()[]{}";
    Solution solution;

    cout << solution.isValid(s) << endl;
}