/**
 * ����������������BST���ĸ��ڵ�root��һ������ֵval��
 * ����Ҫ�� BST ���ҵ��ڵ�ֵ����val�Ľڵ㡣 �����Ըýڵ�Ϊ���������� ����ڵ㲻���ڣ��򷵻�null��
 */
#include "binaryTree.h"

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) return root;
        TreeNode* result = nullptr;
        if (root->val < val) result = searchBST(root->right, val);
        if (root->val > val) result = searchBST(root->left, val);
        return result;

        if (root == nullptr || root->val == val) return root;
        if (root->val < val) return searchBST(root->right, val);
        if (root->val > val) return searchBST(root->left, val);
        return nullptr;
    }

    TreeNode* searchBST2(TreeNode* root, int val) {
        while (root != nullptr) {
            if (root->val > val) root = root->left;
            else if (root->val < val) root = root->right;
            else return root;
        }
        return nullptr;
    }
};

int main() {
    vector<int> root = {4, 2, 7, 1, 3};
    int val = 2;
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    TreeNode* result = solution.searchBST2(treeRoot, val);
    levelOrderOutput(result);
}