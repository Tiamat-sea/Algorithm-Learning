#ifndef BINARY_TREE_BINARYTREE_H
#define BINARY_TREE_BINARYTREE_H

#define null INT_MAX//定义null为int型最大值表示指针指向nullptr
using namespace std;

//二叉树定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //BINARY_TREE_BINARYTREE_H