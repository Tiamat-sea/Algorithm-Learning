/*给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 */

#include <iostream>
#include <vector>
#include "linked_list.h"
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
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

int main() {
    int data[] = {1, 2, 3, 4, 5};
    vector<int> swap(begin(data), end(data));
    Solution solution;

    ListNode* head = buildLinkedList(swap);

    showLinkedList(head);

    ListNode* newHead = solution.reverseList(head);
    showLinkedList(newHead);

}