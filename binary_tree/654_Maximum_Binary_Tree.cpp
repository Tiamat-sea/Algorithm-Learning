/**
 * ����һ�����ظ�����������nums ����������������������㷨��nums �ݹ�ع���:
 * ����һ�����ڵ㣬��ֵΪnums �е����ֵ��
 * �ݹ�������ֵ��ߵ�������ǰ׺�Ϲ�����������
 * �ݹ�������ֵ �ұ� ���������׺�Ϲ�����������
 * ����nums ������ �������� ��
*/
#include "binaryTree.h"
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        return traversal(nums, 0, nums.size());
    }

private:
    TreeNode* traversal(vector<int>& nums, int begin, int end) {
        int delimiterIndex = begin;
        for (int i = begin + 1; i < end; ++i) {
            if (nums[i] > nums[delimiterIndex]) {
                delimiterIndex = i;
            }
        }
        TreeNode* root = new TreeNode(nums[delimiterIndex]);
        if (end - begin == 0) return nullptr;
        if (end - begin == 1) return root;
        int leftBegin = begin;
        int leftEnd = delimiterIndex;
        int rightBegin = delimiterIndex + 1;
        int rightEnd = end;
        root->left = traversal(nums, leftBegin, leftEnd);
        root->right = traversal(nums, rightBegin, rightEnd);
        return root;
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    Solution solution;
    TreeNode* root = solution.constructMaximumBinaryTree(nums);
    levelOrderOutput(root);

    return 0;
}