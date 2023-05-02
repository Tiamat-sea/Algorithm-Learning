/**
 * 二叉树的定义、构造、遍历
 * 例：
 * 前序： 5 4 1 2 6 7 8
 * 中序： 1 4 2 5 7 6 8
 * 后序： 1 2 4 7 8 6 5
 * 层序： 5 4 6 1 2 7 8
 *         5
 *     4       6
 *   1   2   7   8
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "binaryTree.h"
using namespace std;

//递归遍历|深度优先
class RecursiveTraversal {
public:
    vector<int> traversal(TreeNode* root, const string& function) {
        vector<int> result;
        if (function == "preorder") preorderTraversal(root, result);
        if (function == "inorder") inorderTraversal(root, result);
        if (function == "postorder") postorderTraversal(root, result);
        return result;
    }

private:
    void preorderTraversal(TreeNode* cur, vector<int>& vec) {//前序遍历
        if (cur == nullptr) return;
        vec.push_back(cur->val);
        preorderTraversal(cur->left, vec);
        preorderTraversal(cur->right, vec);
    }

    void inorderTraversal(TreeNode* cur, vector<int>& vec) {//中序遍历
        if (cur == nullptr) return;
        inorderTraversal(cur->left, vec);
        vec.push_back(cur->val);
        inorderTraversal(cur->right, vec);
    }

    void postorderTraversal(TreeNode* cur, vector<int>& vec) {//后序遍历
        if (cur == nullptr) return;
        postorderTraversal(cur->left, vec);
        postorderTraversal(cur->right, vec);
        vec.push_back(cur->val);
    }
};

//迭代遍历|非递归遍历|深度优先
class IterativeTraversal {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == nullptr) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == nullptr) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

//统一方式迭代|深度优先
class UnifiedIterativeTraversal {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop();
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
                st.push(node);
                st.push(nullptr);
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop();
                if (node->right) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if (node->left) st.push(node->left);
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop();
                st.push(node);
                st.push(nullptr);
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};

//层序遍历|广度优先|递归&迭代
class LevelTraversal {
public:
    vector<vector<int>> iterativeLevelTraversal(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }

    vector<vector<int>> recursiveLevelTraversal(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        recursiveTraversal(root, result, depth);
        return result;
    }

    void recursiveTraversal(TreeNode* cur, vector<vector<int>>& result, int depth) {
        if (cur == nullptr) return;
        if (result.size() == depth) result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        recursiveTraversal(cur->left, result, depth + 1);
        recursiveTraversal(cur->right, result, depth + 1);
    }
};

int main() {
    vector<int> sequence_num {5, 4, 6, 1, 2, 7, 8};
    TreeNode* root;
}