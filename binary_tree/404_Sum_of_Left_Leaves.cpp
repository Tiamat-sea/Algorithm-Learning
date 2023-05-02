/**
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 */
#include <iostream>
#include <stack>
#include <vector>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        int result = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) result += node->left->val;
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return result;
    }
};

class Solution2 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
//        if (root->left == nullptr && root->right == nullptr) return 0;
        int leftValue = sumOfLeftLeaves(root->left);
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) leftValue = root->left->val;
        int rightValue = sumOfLeftLeaves(root->right);
        int sum = leftValue + rightValue;
        return sum;
    }
};

int main() {
    vector<int> root = {3, 9, 20, null, null, 15, 7};
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    int result = solution.sumOfLeftLeaves(treeRoot);
    cout << result << endl;
}