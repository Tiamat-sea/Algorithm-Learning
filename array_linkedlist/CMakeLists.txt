cmake_minimum_required(VERSION 3.23)
project(leetcode-array_linkedlist)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(0_test                               0_test.cpp)
add_executable(19_remove_nth_node_from_end_of_list  19_remove_nth_node_from_end_of_list.cpp)
add_executable(24_swap_nodes_in_pairs               24_swap_nodes_in_pairs.cpp)
add_executable(27_remove_element                    27_remove_element.cpp)
add_executable(59_spiral_matrix_II                  vector_output.h         59_spiral_matrix_II.cpp)
add_executable(142_Linked_List_Cycle_II             142_Linked_List_Cycle_II.cpp)
add_executable(203_remove_linked_list_elements      203_remove_linked_list_elements.cpp)
add_executable(206_reverse_linked_list              linked_list.h           206_reverse_linked_list.cpp)
add_executable(209_minimum_size_subarray_sum        209_minimum_size_subarray_sum.cpp)
add_executable(704_binary_search                    704_binary_search.cpp)
add_executable(707_design_linked_list               707_design_linked_list.cpp)
add_executable(977_squares_of_a_sorted_array        vector_output.h         977_squares_of_a_sorted_array.cpp)

add_executable(02_07_Intersection_of_Two_Linked_Lists_LCCI 02_07_Intersection_of_Two_Linked_Lists_LCCI.cpp)