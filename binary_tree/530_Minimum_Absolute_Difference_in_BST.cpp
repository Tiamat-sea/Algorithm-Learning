/**
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 * 差值是一个正数，其数值等于两值之差的绝对值。
 */
#include "binaryTree.h"

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vec.clear();
        traversal(root);
        int minGap = INT_MAX;
        for (int i = 1; i < vec.size(); ++i) {
            minGap = min(minGap, vec[i] - vec[i - 1]);
        }
        return minGap;
    }

private:
    vector<int> vec;

    void traversal(TreeNode* cur) {
        if (cur == nullptr) return;
        traversal(cur->left);
        vec.push_back(cur->val);
        traversal(cur->right);
    }
};

class Solution2 {
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return minGap;
    }

private:
    int minGap = INT_MAX;
    TreeNode* pre = nullptr;

    void traversal(TreeNode* cur) {
        if (cur == nullptr) return;
        traversal(cur->left);
        if (pre != nullptr) {
            minGap = min(minGap, cur->val - pre->val);
        }
        pre = cur;
        traversal(cur->right);
    }
};

class Solution3 {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        int minGap = INT_MAX;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top();
                st.pop();
                if (pre != nullptr) {
                    minGap = min(minGap, cur->val - pre->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return minGap;
    }
};

int main() {
    vector<int> root = {4, 2, 6, 1, 3};
    TreeNode* treeRoot = levelOrderBuild(root);
    Solution solution;
    int result = solution.getMinimumDifference(treeRoot);
    cout << result << endl;

    return 0;
}