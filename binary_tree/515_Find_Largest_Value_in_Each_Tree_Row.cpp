/**
 * 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
 */
#include <iostream>
#include <queue>
#include <vector>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int max = que.front()->val;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                max = max < node->val ? node->val : max;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(max);
        }
        return result;
    }
};

int main() {
    vector<int> root = {1, 3, 2, 5, 3, null, 9};
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    vector<int> result = solution.largestValues(treeRoot);
    cout << result << endl;
}