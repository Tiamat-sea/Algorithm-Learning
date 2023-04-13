/**
 * ������Сд��ĸ��ɵ��ַ���S���ظ���ɾ��������ѡ��������������ͬ����ĸ����ɾ�����ǡ�
 * �� S �Ϸ���ִ���ظ���ɾ��������ֱ���޷�����ɾ����
 * ����������ظ���ɾ�������󷵻����յ��ַ������𰸱�֤Ψһ��
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