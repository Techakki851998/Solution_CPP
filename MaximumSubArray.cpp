/*

<-------------Maximum Subarray Sum--------------->

Given an array of n:
 integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

Input

The first input line has an integer n
: the size of the array.

The second line has n
 integers x1,x2,…,xn
: the array values.

Output

Print one integer: the maximum subarray sum.

Constraints
1≤n≤2⋅105

−109≤xi≤109

Example

Input:
8
-1 3 -2 5 3 -5 2 2

Output:
9

*/

#include<iostream>
#include <limits.h>
using namespace std;


// Function to find maximum sum of sub array..............
int maxSum(int a[], int size)
{
	int max_so_far = INT_MIN;
	int max_end = 0;
	for (int i = 0; i < size; i++) {
		max_end = max_end + a[i];
		if (max_so_far < max_end){
			max_so_far = max_end;
        }
		if (max_end < 0){
			max_end = 0;
		}
	}
	return max_so_far;
}

// Main Function.............................
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
	    cin>>a[i];
	}
	int max_sum = maxSum(a, n);
	cout << "Maximum sum is " << max_sum;
	return 0;
}
