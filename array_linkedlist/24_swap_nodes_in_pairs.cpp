/*给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 */

#include<iostream>
#include "linked_list.h"
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto* _dummyHead = new ListNode();
        _dummyHead->next = head;
        ListNode* cur = _dummyHead;
        ListNode* temp1, * temp2;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            temp1 = cur->next;
            temp2 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = temp1;
            cur->next->next->next = temp2;

            cur = cur->next->next;
        }
        return _dummyHead->next;
    }
};

int main() {
    int head[] = {1, 2, 3, 4};
    Solution solution;
    vector<int> swap(begin(head), end(head));
    ListNode* list = buildLinkedList(swap);
    showLinkedList(list);

    ListNode* result = solution.swapPairs(list);
    showLinkedList(result);
}