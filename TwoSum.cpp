/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<int> res;
        
        for (int i = 0; i < sz; i++) {
            int st = i + 1;  // Initialize st to i + 1
            
            while (st < sz && st != i) {  // Add condition st != i to avoid using the same element twice
                if (nums[i] + nums[st] == target) {
                    res.push_back(i);
                    res.push_back(st);
                    return res;  // Return result once a pair is found
                }
                st++;
            }
        }
        
        return res;
    }
};