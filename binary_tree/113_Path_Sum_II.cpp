/**
 * ����������ĸ��ڵ� root ��һ������Ŀ��� targetSum ���ҳ����� �Ӹ��ڵ㵽Ҷ�ӽڵ� ·���ܺ͵��ڸ���Ŀ��͵�·����
 * Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣
*/
#include <iostream>
#include <queue>
#include <vector>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
        result.clear();
        path.clear();
        if (root == nullptr) return result;
        path.push_back(root->val);
        traversal(root, targetSum - root->val);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;

    void traversal(TreeNode* cur, int count) {
        if (cur->left == nullptr && cur->right == nullptr && count == 0) {
            result.push_back(path);
            return;
        }
        if (cur->left == nullptr && cur->right == nullptr) return;
        if (cur->left) {
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count);
            count += cur->left->val;
            path.pop_back();
        }
        if (cur->right) {
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count);
            count += cur->right->val;
            path.pop_back();
        }
        return;
    }
};

int main() {
    vector<int> root = {5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1};
    int targetSum = 22;
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    vector<vector<int>> result = solution.pathSum(treeRoot, targetSum);
    print2DVector(result);
}