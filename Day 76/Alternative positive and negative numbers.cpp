/*
Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
Note: Array should start with a positive number and 0 (zero) should be considered a positive element.
 

Example 1:

Input: 
N = 9
Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
Output:
9 -2 4 -1 5 -5 0 -3 2
Explanation : Positive elements : 9,4,5,0,2
Negative elements : -2,-1,-5,-3
As we need to maintain the relative order of
postive elements and negative elements we will pick
each element from the positive and negative and will
store them. If any of the positive and negative numbers
are completed. we will continue with the remaining signed
elements.The output is 9,-2,4,-1,5,-5,0,-3,2.

Example 2:

Input:
N = 10
Arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
Output:
5 -5 2 -2 4 -8 7 1 8 0
Explanation : Positive elements : 5,2,4,7,1,8,0
Negative elements : -5,-2,-8
As we need to maintain the relative order of
postive elements and negative elements we will pick
each element from the positive and negative and will
store them. If any of the positive and negative numbers
are completed. we will continue with the remaining signed
elements.The output is 5,-5,2,-2,4,-8,7,1,8,0.
Your Task:  

You don't need to read input or print anything. Your task is to complete the function rearrange() which takes the array of integers arr[] and n as parameters. You need to modify the array itself.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
1 ≤ N ≤ 107
-106 ≤ Arr[i] ≤ 107
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    queue<int> q1;
	    queue<int> q2;
	    for (int i = 0; i < n; i++) {
	        if (arr[i] >= 0) {
	            q1.push(arr[i]);
	        }
	        else {
	            q2.push(arr[i]);
	        }
	    }
	    int idx = 0;
	    
	    while (q1.size() && q2.size()) {
	        arr[idx++] = q1.front();
	        q1.pop();
	        arr[idx++] = q2.front();
	        q2.pop();
	    }
	    while(q1.size()) {
	        arr[idx++] = q1.front();
	        q1.pop();
	    }
	    while (q2.size()) {
	        arr[idx++] = q2.front();
	        q2.pop();
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
