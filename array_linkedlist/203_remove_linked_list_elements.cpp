/*给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 删除头结点
        while (head != nullptr && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        // 删除非头结点
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

class Solution1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //删除头节点
        while (head != nullptr && head->val == val) {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        //删除其他节点
        ListNode *cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else {
                cur = cur->next;
            }
        }
        return head;
    }
};

class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val ==val) {
                ListNode *tmp =cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

//创建单链表，从前往后
ListNode* initList(const vector<int> &data) {
    if (data.empty()) {
        return nullptr;
    }
    auto head = new ListNode(data.at(0));
    ListNode* p = head;
    for (int i = 1; i < data.size(); i++) {
        auto q = new ListNode(data.at(i));
        p->next = q;
        p = p->next;
    }
    return head;
}

//输出单链表，从前往后
void showList(ListNode *root) {
    while (root) {
        cout << root->val << ",";
        root = root->next;
    }
    cout << endl;
}

int main() {
    int head[] = {1, 2, 6, 3, 4, 5, 6}, val = 6;
    vector<int> swap(begin(head), end(head));
    Solution2 solution;

    ListNode *root = initList(swap);
    showList(root);

    solution.removeElements(root, val);
    showList(root);

    return 0;
}