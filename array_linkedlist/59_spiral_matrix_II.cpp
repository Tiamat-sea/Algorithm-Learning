/*给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 */

#include <iostream>
#include <vector>
#include "vector_output.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, -1));

        int loop = n / 2;
        int startX = 0, startY = 0;
        int offset = 1;
        int count = 1;
        int i, j;

        while (loop--) {
            i = startX;
            j = startY;
            for (j = startY; j < n - offset; j++) {
                res[i][j] = count++;
            }
            for (i = startX; i < n - offset; i++) {
                res[i][j] = count++;
            }
            for (; j > startY; j--) {
                res[i][j] = count++;
            }
            for (; i > startX; i--) {
                res[i][j] = count++;
            }
            startX++;
            startY++;
            offset++;
        }
        if (n % 2) {
            res[n / 2][n / 2] = count;
        }
        return res;
    }
};


int main() {
    int n = 5;

    Solution solution;

    showTwoVector(solution.generateMatrix(n));
}