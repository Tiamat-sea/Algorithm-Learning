/*给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
 */

#include <iostream>
#include "linked_list.h"
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if (lenA < lenB) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int gap = lenA - lenB;
        while (gap--) {
            curA = curA->next;
        }
        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};



int main() {
    int intersectVal = 8, listA[] = {4, 1, 8, 4, 5}, listB[] = {5, 0, 1, 8, 4, 5}, skipA = 2, skipB = 3;
    //int intersectVal = 0, listA[] = {2, 6, 4}, listB[] = {1, 5}, skipA = 3, skipB = 2;
    vector<int> swapA(begin(listA), end(listA));
    vector<int> swapB(begin(listB), end(listB));
    Solution solution;

    int a, b;
    a = b = 0;

    ListNode* dummyHeadA = new ListNode(), * dummyHeadB = new ListNode(), * curA, * curB;
    curA = dummyHeadA;
    curB = dummyHeadB;
    while (a < skipA) {
        ListNode* node = new ListNode(swapA[a]);
        curA->next = node;
        curA = curA->next;
        a++;
    }
    while (b < skipB) {
        ListNode* node = new ListNode(swapB[b]);
        curB->next = node;
        curB = curB->next;
        b++;
    }
    while (a < swapA.size()) {
        ListNode* node = new ListNode(swapA[a]);
        curA->next = node;
        curB->next = node;
        curA = curA->next;
        curB = curB->next;
        a++;
    }

    showLinkedList(dummyHeadA->next);
    showLinkedList(dummyHeadB->next);
    cout << solution.getIntersectionNode(dummyHeadA->next, dummyHeadB->next)->val;
}
