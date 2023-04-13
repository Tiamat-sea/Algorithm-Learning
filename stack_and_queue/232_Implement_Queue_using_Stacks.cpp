/**
 * �����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����ʵ�� MyQueue �ࣺ
 * void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
 * int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
 * int peek() ���ض��п�ͷ��Ԫ��
 * boolean empty() �������Ϊ�գ����� true �����򣬷��� false
 * ˵����
 * �� ֻ�� ʹ�ñ�׼��ջ���� ���� Ҳ����ֻ��push to top,peek/pop from top,size, ��is empty�����ǺϷ��ġ�
 * ����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
#include <iostream>
#include <stack>
#include <vector>
#include "vector_output.h"
using namespace std;

class MyQueue {
public:
    stack<int, vector<int>> stIn;
    stack<int, vector<int>> stOut;

    MyQueue() = default;

    void push(int x) {
        stIn.push(x);
    }

    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    int peek() {
        int result = this->pop();
        stOut.push(result);
        return result;
    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

vector<string> toTest(vector<string> cmd, vector<vector<int>> data) {
    MyQueue* obj = new MyQueue();
    vector<string> result(cmd.size());
    for (int i = 1; i < cmd.size(); ++i) {
        if (cmd[i] == "MyQueue") MyQueue* obj = new MyQueue();
        else if (cmd[i] == "push") obj->push(data[i][0]);
        else if (cmd[i] == "peek") result[i] = to_string(obj->peek());
        else if (cmd[i] == "pop") result[i] = to_string(obj->pop());
        else if (cmd[i] == "empty") {
            if (obj->empty()) result[i] = "true";
            else result[i] = "false";
        }
    }
    return result;
}

int main() {
    vector<string> cmd {"MyQueue", "push", "push", "peek", "pop", "empty"};
    vector<vector<int>> data {{}, {1}, {2}, {}, {}, {}};

    vector<string> result = toTest(cmd, data);
    cout << result << endl;
}

