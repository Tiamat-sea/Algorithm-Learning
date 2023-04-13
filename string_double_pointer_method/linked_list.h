#ifndef LEETCODE_LINKED_LIST_H
#define LEETCODE_LINKED_LIST_H

#endif //LEETCODE_LINKED_LIST_H

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildLinkedList(vector<int> swap) {
    ListNode* dummyHead = new ListNode();
    ListNode* cur = dummyHead;

    for (int i = 0; i < swap.size(); i++) {
        ListNode* node = new ListNode(swap[i]);
        cur->next = node;
        cur = cur->next;
    }

    return dummyHead->next;
}

void showLinkedList(ListNode* head) {
    ListNode* dummyHead = new ListNode();
    dummyHead->next = head;
    ListNode* cur = dummyHead;
    while (cur->next != nullptr) {
        cout << cur->next->val << " -> ";
        cur = cur->next;
    }
    cout << "nullptr" << endl;
}