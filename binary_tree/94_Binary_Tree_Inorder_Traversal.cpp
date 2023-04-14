/**
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
 * 本题由于需要构造还原二叉树，故未实现能运行的代码，仅编写了核心逻辑部分
 */
#include <iostream>
#include <vector>
#include <stack>
#include "binaryTree.h"
using namespace std;

//递归遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }

private:
    void traversal(TreeNode* cur, vector<int>& vec){
        if (cur == nullptr) return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
};

//迭代遍历1
class Solution2 {
public:
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
};

//迭代遍历2
class Solution3 {
public:
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
};

int main() {
    vector<int> root = {1, null, 2, 3};
}