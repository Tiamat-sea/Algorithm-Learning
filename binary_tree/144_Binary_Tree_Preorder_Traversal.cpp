/**
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
*/
#include <iostream>
#include <vector>
#include <stack>
#include "binaryTree.h"
using namespace std;

//递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }

private:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == nullptr) return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
};

//迭代遍历1
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode*> st;
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
};

//迭代遍历2
class Solution3 {
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
};

int main() {
//    vector<int> root {1, null, 2, 3, 4, null, 5, null, 6};
    vector<int> root = {1, null, 2, 3};
    TreeNode* treeRoot = levelOrderBuild(root);//层序遍历创建二叉树
    Solution solution;
    vector<int> preorder = solution.preorderTraversal(treeRoot);//先序遍历
    cout << preorder << endl;
}