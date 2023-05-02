/**
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
*/
#include <vector>
#include <queue>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
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
};

class Solution2 {
public:
    vector<vector<int>> recursiveLevelTraversal(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        recursiveTraversal(root, result, depth);
        return result;
    }

private:
    void recursiveTraversal(TreeNode* cur, vector<vector<int>>& result, int depth) {
        if (cur == nullptr) return;
        if (result.size() == depth) result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        recursiveTraversal(cur->left, result, depth + 1);
        recursiveTraversal(cur->right, result, depth + 1);
    }
};

int main() {
    vector<int> root = {3, 9, 20, null, null, 15, 7};
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    vector<vector<int>> levelOrder = solution.levelOrder(treeRoot);
    print2DVector(levelOrder);
}