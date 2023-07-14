/*

Longest Valid Parentheses

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring
.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // Initialize the stack with a sentinel value

        int maxLength = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);  // Push the index of opening parenthesis
            } else {
                st.pop();  // Pop the top index from the stack

                if (st.empty()) {
                    st.push(i);  // Push the current index as the new sentinel value
                } else {
                    int length = i - st.top();  // Calculate the length of the valid substring
                    maxLength = max(maxLength, length);  // Update maxLength if necessary
                }
            }
        }

        return maxLength;
    }
};
