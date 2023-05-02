/**
 * ����һ���������ĸ��ڵ� root ���� ����˳�� ���������дӸ��ڵ㵽Ҷ�ӽڵ��·����
 * Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣
 */
#include <iostream>
#include <stack>
#include <vector>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (root != nullptr) traversal(root, path, result);
        return result;
    }

private:
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr) {
            string sPath;
            for (int i = 0; i < path.size() - 1; ++i) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (cur->left) {
            traversal(cur->left, path, result);
            path.pop_back();
        }
        if (cur->right) {
            traversal(cur->right, path, result);
            path.pop_back();
        }
    }

    void traversal(TreeNode* cur, string path, vector<string>& result) {
        path += to_string(cur->val);
        if (cur->left == nullptr && cur->right == nullptr) {
            result.push_back(path);
            return;
        }
        if (cur->left) traversal(cur->left, path + "->", result);
        if (cur->right) traversal(cur->right, path + "->", result);
    }
};

class Solution2 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> treeSt;
        stack<string> pathSt;
        vector<string> result;
        if (root == nullptr) return result;
        treeSt.push(root);
        pathSt.push(to_string(root->val));
        while (!treeSt.empty()) {
            TreeNode* node = treeSt.top(); treeSt.pop();
            string path = pathSt.top(); pathSt.pop();
            if (node->left == nullptr && node->right == nullptr) result.push_back(path);
            if (node->right) {
                treeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
            if (node->left) {
                treeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
        }
        return result;
    }
};

int main() {
    vector<int> root = {1, 2, 3, null, 5};
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    vector<string> result = solution.binaryTreePaths(treeRoot);
    cout << result << endl;
}