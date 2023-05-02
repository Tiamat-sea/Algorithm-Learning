/**
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 */
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }

private:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        else if (left->val != right->val) return false;
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            TreeNode* leftNode = que.front(); que.pop();
            TreeNode* rightNode = que.front(); que.pop();
            if (!leftNode && !rightNode) continue;
            if (!leftNode || !rightNode || (leftNode->val != rightNode->val)) return false;
            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        return true;
    }
};

class Solution3 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while (!st.empty()) {
            TreeNode* rightNode = st.top(); st.pop();
            TreeNode* leftNode = st.top(); st.pop();
            if (!leftNode && !rightNode) continue;
            if (!leftNode || !rightNode || (leftNode->val != rightNode->val)) return false;
            st.push(leftNode->left);
            st.push(rightNode->right);
            st.push(leftNode->right);
            st.push(rightNode->left);
        }
        return true;
    }
};

int main() {
    vector<int> root = {1, 2, 2, 3, 4, 4, 3};
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    bool result = solution.isSymmetric(treeRoot);
    cout << result << endl;
}