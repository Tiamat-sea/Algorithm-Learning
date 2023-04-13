/**
 * 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：实现 MyQueue 类：
 * void push(int x) 将元素 x 推到队列的末尾
 * int pop() 从队列的开头移除并返回元素
 * int peek() 返回队列开头的元素
 * boolean empty() 如果队列为空，返回 true ；否则，返回 false
 * 说明：
 * 你 只能 使用标准的栈操作 —— 也就是只有push to top,peek/pop from top,size, 和is empty操作是合法的。
 * 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
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

