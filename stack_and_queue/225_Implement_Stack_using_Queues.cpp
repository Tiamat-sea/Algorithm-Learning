/**
 * �����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����
 * ʵ�� MyStack �ࣺ
 * void push(int x) ��Ԫ�� x ѹ��ջ����
 * int pop() �Ƴ�������ջ��Ԫ�ء�
 * int top() ����ջ��Ԫ�ء�
 * boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��
 * ע�⣺
 * ��ֻ��ʹ�ö��еĻ������� ���� Ҳ����push to back��peek/pop from front��size ��is empty��Щ������
 * ����ʹ�õ�����Ҳ��֧�ֶ��С������ʹ�� list ���б����� deque��˫�˶��У���ģ��һ������, ֻҪ�Ǳ�׼�Ķ��в������ɡ�
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
*/
#include <iostream>
#include <queue>
#include <vector>
#include "vector_output.h"
using namespace std;

class MyStack {
public:
    queue<int> que;

    MyStack() {}

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        size--;
        while (size--) {
            que.push(que.front());
            que.pop();
        }
        int result = que.front();
        que.pop();
        return result;
    }

    int top() {
        return que.back();
    }

    bool empty() {
        return que.empty();
    }
};

vector<string> toTest(vector<string> cmd, vector<vector<int>> data) {
    MyStack* obj = new MyStack();
    vector<string> result(cmd.size());
    for (int i = 1; i < cmd.size(); ++i) {
        if (cmd[i] == "MyStack") MyStack* obj = new MyStack();
        else if (cmd[i] == "push") obj->push(data[i][0]);
        else if (cmd[i] == "top") result[i] = to_string(obj->top());
        else if (cmd[i] == "pop") result[i] = to_string(obj->pop());
        else if (cmd[i] == "empty") {
            if (obj->empty()) result[i] = "true";
            else result[i] = "false";
        }
    }
    return result;
}

int main() {
    vector<string> cmd {"MyStack", "push", "push", "top", "pop", "empty"};
    vector<vector<int>> data {{}, {1}, {2}, {}, {}, {}};

    vector<string> result = toTest(cmd, data);
    cout << result << endl;
}