/*
Valid Perfect Square

Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) {
            return true;
        }
        
        long left = 1;
        long right = num;
        
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long midSquare = mid * mid;
            
            if (midSquare == num) {
                return true;
            } else if (midSquare > num) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return false;
    }
};

int main() {
    int num = 16;
    Solution solution;
    bool isPerfect = solution.isPerfectSquare(num);
    std::cout << "Is " << num << " a perfect square? " << (isPerfect ? "Yes" : "No") << std::endl;
    return 0;
}
