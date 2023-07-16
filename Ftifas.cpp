/*
Find Target Indices After Sorting Array

You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

 

Example 1:

Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.
*/

#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        std::vector<int> sortedIndices;
        std::vector<int> sortedNums(nums);
        std::sort(sortedNums.begin(), sortedNums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (sortedNums[i] == target) {
                sortedIndices.push_back(i);
            }
        }
        return sortedIndices;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;
    Solution solution;
    std::vector<int> sortedIndices = solution.targetIndices(nums, target);
    for (int i = 0; i < sortedIndices.size(); i++) {
        std::cout << sortedIndices[i] << " ";
    }
    return 0;
}
