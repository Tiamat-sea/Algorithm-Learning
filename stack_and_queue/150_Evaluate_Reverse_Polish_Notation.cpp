/**
 * ����һ���ַ������� tokens ����ʾһ�������沨����ʾ�� ��ʾ���������ʽ��
 * �������ñ��ʽ������һ����ʾ���ʽֵ��������
 * ע�⣺
 * ��Ч�����Ϊ '+'��'-'��'*' �� '/' ��
 * ÿ����������������󣩶�������һ������������һ�����ʽ��
 * ��������֮��ĳ������� ����ض� ��
 * ���ʽ�в����������㡣
 * ������һ�������沨����ʾ����ʾ���������ʽ��
 * �𰸼������м������������ 32 λ ������ʾ��
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