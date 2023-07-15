/*
Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.


Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        int i=0;
        int j=height.size()-1;
        int sum=0;
      
       int l_max=0;
        int r_max=0;

        while(i<j){
              l_max=max(l_max,height[i]);
              r_max=max(r_max,height[j]);

            if(l_max<r_max){
                sum+=l_max-height[i];
                   i++;
            }
            else {
                sum+=r_max-height[j];
                j--;
            }
        }
        return sum;
    }
};