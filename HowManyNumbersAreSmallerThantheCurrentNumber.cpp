/*
How Many Numbers Are Smaller Than the Current Number

Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.


Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
*/

#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        std::vector<int> counts(nums.size(), 0);
        
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] < nums[i]) {
                    count++;
                }
            }
            
            counts[i] = count;
        }
        
        return counts;
    }
};

int main() {
    std::vector<int> nums = {8, 1, 2, 2, 3};
    Solution solution;
    std::vector<int> counts = solution.smallerNumbersThanCurrent(nums);
    
    std::cout << "Counts: ";
    for (const auto& count : counts) {
        std::cout << count << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
