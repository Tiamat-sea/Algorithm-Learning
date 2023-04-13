/**
* ���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣�����������û�н��㣬���� null ��
*/
#include <iostream>
#include <vector>
#include "linked_list.h"
using namespace std;

class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while (curB) {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if (lenA > lenB) {//��֤A��B��
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int gap = lenB - lenA;//���Ȳ�
        while (gap--) {
            curB = curB->next;
        }
        while (curA != nullptr) {
            if (curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};

//�����ཻ����
void buildAnnularLinkedList(ListNode* dummyHeadA, ListNode* dummyHeadB, vector<int> listA, vector<int> listB, int skipA, int skipB) {
    ListNode* curA, * curB;
    curA = dummyHeadA;
    curB = dummyHeadB;
    dummyHeadA->next = buildLinkedList(listA);
    dummyHeadB->next = buildLinkedList(listB);
    while (skipA--) {
        curA = curA->next;
    }
    while (skipB--) {
        curB = curB->next;
    }
    ListNode* temp = curB->next;
    while (temp) {
        ListNode* backup = temp;
        temp = temp->next;
        delete backup;
    }
    curB->next = curA->next;
}

//��ַ����˹���֤
void showAddress(ListNode* HeadA, ListNode* HeadB) {
    ListNode* curA = HeadA;
    ListNode* curB = HeadB;
    while (curA) {
        cout << curA << "  ";
        curA = curA->next;
    }
    cout << endl;
    while (curB) {
        cout << curB << "  ";
        curB = curB->next;
    }
    cout << endl;
}

int main() {
    vector<int> listA {4, 1, 8, 4, 5};
    vector<int> listB {5, 0, 1, 8, 4, 5};
    int skipA = 2, skipB = 3, intersectVal = 8;
    Solution solution;

    ListNode* dummyHeadA = new ListNode(-1);
    ListNode* dummyHeadB = new ListNode(-1);
    buildAnnularLinkedList(dummyHeadA, dummyHeadB, listA, listB, skipA, skipB);
    ListNode* headA = dummyHeadA->next;
    ListNode* headB = dummyHeadB->next;
    delete dummyHeadA;
    delete dummyHeadB;

    showLinkedList(headA);
    showLinkedList(headB);
    showAddress(headA, headB);

    ListNode* result = solution.getIntersectionNode(headA, headB);

    cout << result << "  " << result->val << endl;
}