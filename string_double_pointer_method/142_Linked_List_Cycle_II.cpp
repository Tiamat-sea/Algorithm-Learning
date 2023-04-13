/**
* ����һ�������ͷ�ڵ� head����������ʼ�뻷�ĵ�һ���ڵ㡣��������޻����򷵻�null��
* �����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ�����
* �е�λ�ã������� 0 ��ʼ������� pos �� -1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������
* �������޸�����
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

//������������
ListNode* buildCycleLinkedList(vector<int> list, int pos) {
    ListNode* head = buildLinkedList(list);
    ListNode* temp;//���滷��λ�õĵ�ַ
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