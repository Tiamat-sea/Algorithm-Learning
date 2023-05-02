/**
 * ����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
 * �����У�һ�ø߶�ƽ�����������Ϊ��
 * һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
 */
#include <iostream>
#include <vector>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }

private:
    int getHeight(TreeNode* node) {
        if (node == nullptr) return 0;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        if (leftHeight == -1 || rightHeight == -1) return -1;
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    vector<int> root = {3, 9, 20, null, null, 15, 7};
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    bool result = solution.isBalanced(treeRoot);
    cout << result << endl;
}