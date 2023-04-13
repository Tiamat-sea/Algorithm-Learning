/**
* 给定一个链表的头节点 head，返回链表开始入环的第一个节点。如果链表无环，则返回null。
* 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表
* 中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
* 不允许修改链表。
*/

#include <iostream>
#include "linked_list.h"
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

//构建环形链表
ListNode* buildCycleLinkedList(vector<int> list, int pos) {
    ListNode* head = buildLinkedList(list);
    ListNode* temp;//保存环的位置的地址
    ListNode* cur = head;
    while (pos--) {
        cur = cur->next;
    }
    temp = cur;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = temp;
    return head;
}

int main() {
    vector<int> head {3, 2, 0, -4};
    int pos = 1;
    Solution solution;
    ListNode* list = buildCycleLinkedList(head, pos);

    ListNode* result = solution.detectCycle(list);
    cout << result << "  " << result->val << endl;
}