cmake_minimum_required(VERSION 3.23)
project(binary_tree)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(binary_tree                                                      binaryTree.h binary_tree.cpp)
add_executable(144_Binary_Tree_Preorder_Traversal                               144_Binary_Tree_Preorder_Traversal.cpp)
add_executable(94_Binary_Tree_Inorder_Traversal                                 94_Binary_Tree_Inorder_Traversal.cpp)
add_executable(145_Binary_Tree_Postorder_Traversal                              145_Binary_Tree_Postorder_Traversal.cpp)
add_executable(102_Binary_Tree_Level_Order_Traversal                            102_Binary_Tree_Level_Order_Traversal.cpp)
add_executable(107_Binary_Tree_Level_Order_Traversal_II                         107_Binary_Tree_Level_Order_Traversal_II.cpp)
add_executable(199_Binary_Tree_Right_Side_View                                  199_Binary_Tree_Right_Side_View.cpp)
add_executable(637_Average_of_Levels_in_Binary_Tree                             637_Average_of_Levels_in_Binary_Tree.cpp)
add_executable(429_N-ary_Tree_Level_Order_Traversal                             429_N-ary_Tree_Level_Order_Traversal.cpp)#n叉树，未完成，仅核心代码逻辑
add_executable(515_Find_Largest_Value_in_Each_Tree_Row                          515_Find_Largest_Value_in_Each_Tree_Row.cpp)
add_executable(116_Populating_Next_Right_Pointers_in_Each_Node                  116_Populating_Next_Right_Pointers_in_Each_Node.cpp)#遍历方式有别，未完成，仅核心代码逻辑
add_executable(117_Populating_Next_Right_Pointers_in_Each_Node_II               117_Populating_Next_Right_Pointers_in_Each_Node_II.cpp)#遍历方式有别，未完成，仅核心代码逻辑
add_executable(104_Maximum_Depth_of_Binary_Tree                                 104_Maximum_Depth_of_Binary_Tree.cpp)
add_executable(111_Minimum_Depth_of_Binary_Tree                                 111_Minimum_Depth_of_Binary_Tree.cpp)
add_executable(226_Invert_Binary_Tree                                           226_Invert_Binary_Tree.cpp)
add_executable(101_Symmetric_Tree                                               101_Symmetric_Tree.cpp)
add_executable(559_Maximum_Depth_of_N-ary_Tree                                  559_Maximum_Depth_of_N-ary_Tree.cpp)#n叉树，未完成，仅核心代码逻辑
add_executable(222_Count_Complete_Tree_Nodes                                    222_Count_Complete_Tree_Nodes.cpp)
add_executable(110_Balanced_Binary_Tree                                         110_Balanced_Binary_Tree.cpp)
add_executable(257_Binary_Tree_Paths                                            257_Binary_Tree_Paths.cpp)
add_executable(404_Sum_of_Left_Leaves                                           404_Sum_of_Left_Leaves.cpp)
add_executable(513_Find_Bottom_Left_Tree_Value                                  513_Find_Bottom_Left_Tree_Value.cpp)
add_executable(112_Path_Sum                                                     112_Path_Sum.cpp)
add_executable(113_Path_Sum_II                                                  113_Path_Sum_II.cpp)
add_executable(106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal   106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp)
add_executable(105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal    105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp)
add_executable(654_Maximum_Binary_Tree                                          654_Maximum_Binary_Tree.cpp)
add_executable(617_Merge_Two_Binary_Trees                                       617_Merge_Two_Binary_Trees.cpp)
add_executable(700_Search_in_a_Binary_Search_Tree                               700_Search_in_a_Binary_Search_Tree.cpp)
add_executable(98_Validate_Binary_Search_Tree                                   98_Validate_Binary_Search_Tree.cpp)
add_executable(530_Minimum_Absolute_Difference_in_BST                           530_Minimum_Absolute_Difference_in_BST.cpp)#二叉搜索树的最小绝对差



add_executable(test test.cpp)