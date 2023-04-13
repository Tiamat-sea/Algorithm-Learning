/**
 * 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
 * 实现 MyStack 类：
 * void push(int x) 将元素 x 压入栈顶。
 * int pop() 移除并返回栈顶元素。
 * int top() 返回栈顶元素。
 * boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 * 注意：
 * 你只能使用队列的基本操作 —— 也就是push to back、peek/pop from front、size 和is empty这些操作。
 * 你所使用的语言也许不支持队列。你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列, 只要是标准的队列操作即可。
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