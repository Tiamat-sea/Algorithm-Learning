/**
 * 给你一个字符串数组 tokens ，表示一个根据逆波兰表示法 表示的算术表达式。
 * 请你计算该表达式。返回一个表示表达式值的整数。
 * 注意：
 * 有效的算符为 '+'、'-'、'*' 和 '/' 。
 * 每个操作数（运算对象）都可以是一个整数或者另一个表达式。
 * 两个整数之间的除法总是 向零截断 。
 * 表达式中不含除零运算。
 * 输入是一个根据逆波兰表示法表示的算术表达式。
 * 答案及所有中间计算结果可以用 32 位 整数表示。
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (string s : tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/") st.push(stoll(s));
            else {
                long long result;
                long long num2 = st.top();
                st.pop();
                long long num1 = st.top();
                st.pop();
                if (s == "+") result = num1 + num2;
                else if (s == "-") result = num1 - num2;
                else if (s == "*") result = num1 * num2;
                else result = num1 / num2;
                st.push(result);
            }
        }
        return st.top();
    }
};

int main() {
    vector<string> tokens {"2", "1", "+", "3", "*"};
    Solution solution;

    cout << solution.evalRPN(tokens) << endl;
}