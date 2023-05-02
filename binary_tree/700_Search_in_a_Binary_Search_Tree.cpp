/**
 * 给定二叉搜索树（BST）的根节点root和一个整数值val。
 * 你需要在 BST 中找到节点值等于val的节点。 返回以该节点为根的子树。 如果节点不存在，则返回null。
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