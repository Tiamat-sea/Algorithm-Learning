/*给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 */
#include<iostream>
#include "linked_list.h"
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto* _dummyHead = new ListNode();
        _dummyHead->next = head;
        ListNode* fast, * slow, * temp;
        fast = slow = _dummyHead;
        while (fast->next != nullptr) {
            if (n > 0) {
                fast = fast->next;
                n--;
            }
            else {
                fast = fast->next;
                slow = slow->next;
            }
        }
        temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return _dummyHead->next;
    }
};

int main() {
    int head[] = {1, 2, 3, 4, 5}, n = 2;
    Solution solution;
    vector<int> swap(begin(head), end(head));
    ListNode* list = buildLinkedList(swap);
    showLinkedList(list);

    ListNode* result = solution.removeNthFromEnd(list, n);
    showLinkedList(result);
}