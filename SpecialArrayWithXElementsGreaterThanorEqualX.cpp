/*
Special Array With X Elements Greater Than or Equal X

You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

 

Example 1:

Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.
*/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int specialArray(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] >= nums.size() - mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        if (left < nums.size() && nums[left] >= nums.size() - left) {
            return nums.size() - left;
        }
        
        return -1;
    }
};

int main() {
    std::vector<int> nums = {3, 5};
    Solution solution;
    int x = solution.specialArray(nums);
    std::cout << "x: " << x << std::endl;
    return 0;
}

