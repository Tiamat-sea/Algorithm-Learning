/**
 * 给你二叉树的根节点root 和一个表示目标和的整数targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于
 * 目标和targetSum 。如果存在，返回 true ；否则，返回 false 。
 * 叶子节点 是指没有子节点的节点。
*/
#include <iostream>
#include <stack>
#include <vector>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return traversal(root, targetSum - root->val);
    }

//    bool hasPathSum(TreeNode* root, int targetSum) {
//        if (root == nullptr) return false;
//        if (root->left == nullptr && root->right == nullptr && targetSum == root->val) return true;
//        return (hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val));
//    }

private:
    bool traversal(TreeNode* cur, int count) {
        if (cur->left == nullptr && cur->right == nullptr && count == 0) return true;
        if (cur->left == nullptr && cur->right == nullptr) return false;
        if (cur->left) {
            if (traversal(cur->left, count - cur->left->val)) return true;
        }
        if (cur->right) {
            if (traversal(cur->right, count - cur->right->val)) return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        stack<pair<TreeNode*, int>> st;
        st.push(pair<TreeNode*, int> (root, root->val));
        while (!st.empty()) {
            pair<TreeNode*, int> node = st.top();
            st.pop();
            if (node.first->left == nullptr && node.first->right == nullptr && targetSum == node.second) return true;
            if (node.first->right != nullptr) st.push(pair<TreeNode*, int> (node.first->right, node.second + node.first->right->val));
            if (node.first->left != nullptr) st.push(pair<TreeNode*, int> (node.first->left, node.second + node.first->left->val));
        }
        return false;
    }
};

int main() {
    vector<int> root = {5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1};
    int targetSum = 22;
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    bool result = solution.hasPathSum(treeRoot, targetSum);
    cout << result << endl;
}