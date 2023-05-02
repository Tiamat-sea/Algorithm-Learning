/**
 * �������ö������� root1 �� root2 ��
 * ����һ�£����㽫����һ�ø��ǵ���һ��֮��ʱ���������ϵ�һЩ�ڵ㽫���ص�������һЩ���ᣩ������Ҫ�����������ϲ���һ���¶��������ϲ��Ĺ����ǣ���������ڵ�
 * �ص�����ô���������ڵ��ֵ�����Ϊ�ϲ���ڵ����ֵ�����򣬲�Ϊ null �Ľڵ㽫ֱ����Ϊ�¶������Ľڵ㡣
 * ���غϲ���Ķ�������
 * ע��: �ϲ����̱�����������ĸ��ڵ㿪ʼ��
 */
#include "binaryTree.h"
#include <queue>

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }

    TreeNode* mergeTrees2(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        TreeNode* root = new TreeNode();
        root->val = root1->val + root2->val;
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }

    TreeNode* mergeTrees3(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty()) {
            TreeNode* node1 = que.front(); que.pop();
            TreeNode* node2 = que.front(); que.pop();
            node1->val += node2->val;
            if (node1->left != nullptr && node2->left != nullptr) {
                que.push(node1->left);
                que.push(node2->left);
            }
            if (node1->right != nullptr && node2->right != nullptr) {
                que.push(node1->right);
                que.push(node2->right);
            }
            if (node1->left == nullptr && node2->left != nullptr) {
                node1->left = node2->left;
            }
            if (node1->right == nullptr && node2->right != nullptr) {
                node1->right = node2->right;
            }
        }
        return root1;
    }
};

int main() {
    vector<int> root1 = {1, 3, 2, 5}, root2 = {2, 1, 3, null, 4, null, 7};
    Solution solution;
    TreeNode* treeRoot1 = levelOrderBuild(root1);
    TreeNode* treeRoot2 = levelOrderBuild(root2);
    TreeNode* newRoot = solution.mergeTrees3(treeRoot1, treeRoot2);
    levelOrderOutput(newRoot);
}