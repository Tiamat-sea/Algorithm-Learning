/**
 * ���������������� inorder �� postorder ������ inorder �Ƕ���������������� postorder ��ͬһ�����ĺ�����������㹹�첢������Ŷ�������
*/
#include "binaryTree.h"
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }

private:
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd) {
        if (postorderBegin == postorderEnd) return nullptr;
        int rootValue = postorder[postorderEnd - 1];
        TreeNode* root = new TreeNode(rootValue);
        if (postorderEnd - postorderBegin == 1) return root;

        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; ++delimiterIndex) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;
        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin;
        int rightPostorderBegin = postorderBegin + delimiterIndex - inorderBegin;
        int rightPostorderEnd = postorderEnd - 1;

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);
        return root;
    }
};

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7}, postorder = {9, 15, 7, 20, 3};
    Solution solution;
    TreeNode* root = solution.buildTree(inorder, postorder);

    levelOrderOutput(root);
}