/*给定一个链表的头节点 head，返回链表开始入环的第一个节点。如果链表无环，则返回null。
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到
 * 链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
 * 不允许修改 链表。
 */



#include <iostream>
#include <unordered_set>
#include "linked_list.h"
using namespace std;

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> record;
        ListNode* cur = head;
        while (cur != nullptr) {
            if (record.find(cur) != record.end()) {
                return cur;
            }
            else {
                record.insert(cur);
            }
            cur = cur->next;
        }
        return nullptr;
    }

    ListNode* detectCycle2(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
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

int main() {
    Solution solution;
//    int head[] = {1}, pos = -1;
//    int head[] = {1, 2}, pos = 0;
    int head[] = {3, 2, 0, -4}, pos = 1;
    vector<int> swap(begin(head), end(head));
    ListNode* list = buildLinkedList(swap);

    //构建环形
    ListNode* cur = list, * temp;
    cur = list;
    if (pos >= 0) {
        while (pos--) {
            cur = cur->next;
        }
        temp = cur;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = temp;
    }

    //环形链表输出
    unordered_set<ListNode*> record;
    cur = list;
    while (cur != nullptr) {
        if (record.find(cur) != record.end()) {
            cout << "找到了环形，环形开始的节点的val为：" << cur->val << endl;
            break;
        }
        else if (record.find(cur) == record.end()) {
            record.insert(cur);
            cout << cur->val << " -> ";
        }
        cur = cur->next;
    }
    if (cur == nullptr) {
        cout << "nullptr" << endl;
    }

    if (solution.detectCycle(list)) {
        cout << solution.detectCycle2(list)->val << endl;
    }
    else {
        cout << "nullptr" << endl;
    }

}