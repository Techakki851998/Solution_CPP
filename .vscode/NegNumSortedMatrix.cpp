/*
Count Negative Numbers in a Sorted Matrix

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
*/

#include<iostream>
#include<vector>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        int row = 0;
        int col = n - 1;
        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                count += (m - row);
                col--;
            } else {
                row++;
            }
        }
        return count;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };
    Solution solution;
    int negCount = solution.countNegatives(grid);
    std::cout << "Number of negative numbers: " << negCount << std::endl;
    return 0;
}
