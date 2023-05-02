/**
 * ����һ���������ĸ��ڵ� root ���ж����Ƿ���һ����Ч�Ķ�����������
 * ��Ч �����������������£�
 * �ڵ��������ֻ���� С�� ��ǰ�ڵ������
 * �ڵ��������ֻ���� ���� ��ǰ�ڵ������
 * �������������������������Ҳ�Ƕ�����������
 */
#include "binaryTree.h"
#include <stack>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);
        if (maxValue < root->val) maxValue = root->val;
        else return false;
        bool right = isValidBST(root->right);
        return left && right;
    }

private:
    long long maxValue = LONG_MIN;
};

class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        vec.clear();
        traversal(root);
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i] <= vec[i - 1]) return false;
        }
        return true;
    }

private:
    vector<int> vec;

    void traversal(TreeNode* root) {
        if (root == nullptr) return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }
};

class Solution3 {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);
        if (pre != nullptr && pre->val >= root->val) return false;
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }

private:
    TreeNode* pre = nullptr;
};

class Solution4 {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top();
                st.pop();
                if (pre != nullptr && pre->val >= cur->val) return false;
                pre = cur;
                cur = cur->right;
            }
        }
        return true;
    }
};

int main() {
    vector<int> root = {5, 1, 4, null, null, 3, 6};
    TreeNode* treeRoot = levelOrderBuild(root);
    Solution solution;
    cout << solution.isValidBST(treeRoot) << endl;

    return 0;
}