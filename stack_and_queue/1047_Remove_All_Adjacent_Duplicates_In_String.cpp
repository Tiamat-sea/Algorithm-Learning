/**
 * 给出由小写字母组成的字符串S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 * 在 S 上反复执行重复项删除操作，直到无法继续删除。
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
*/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char ch : s) {
            if (st.empty() || ch != st.top()) st.push(ch);
            else st.pop();
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

class Solution2 {
public:
    string removeDuplicates(string s) {
        string result;
        for (char ch : s) {
            if (result.empty() || ch != result.back()) result.push_back(ch);
            else result.pop_back();
        }
        return result;
    }
};

int main() {
    string s = "abbaca";
    Solution2 solution;

    cout << solution.removeDuplicates(s) << endl;
}