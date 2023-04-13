/**
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 */
#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* tmp;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

class Solution2 {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == nullptr) return pre;
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
};

int main() {
    vector<int> head {1, 2, 3, 4, 5};
    ListNode* list = buildLinkedList(head);
    showLinkedList(list);
    Solution2 solution;

    showLinkedList(solution.reverseList(list));
}