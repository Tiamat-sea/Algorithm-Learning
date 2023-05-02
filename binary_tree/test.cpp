#include <iostream>
#include "binaryTree.h"
using namespace std;


int main() {
    vector<int> levelOrder = {3, 9, 20, null, null, 15, 7};
    TreeNode* root = levelOrderBuild(levelOrder);

    levelOrderOutput(root);
}