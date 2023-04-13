/**
* ����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
*/
#include <iostream>
#include <vector>
#include "linked_list.h"
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummyHead->next;
    }
};

int main() {
    vector<int> head {1, 2, 3, 4, 5};
    int n = 2;
    ListNode* list = buildLinkedList(head);
    showLinkedList(list);
    Solution solution;

    ListNode* result = solution.removeNthFromEnd(list, n);
    showLinkedList(result);
}