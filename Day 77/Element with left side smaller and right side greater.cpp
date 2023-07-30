/*
Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

 

Example 1:

Input:
N = 4
A[] = {4, 2, 5, 7}
Output:
5
Explanation:
Elements on left of 5 are smaller than 5
and on right of it are greater than 5.
 

Example 2:

Input:
N = 3
A[] = {11, 9, 12}
Output:
-1
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findElement() which takes the array A[] and its size N as inputs and returns the required element. If no such element present in array then return -1.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
3 <= N <= 106
1 <= A[i] <= 106
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    bool pmax = false;
    int max = arr[0];
    
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] >= max && !pmax) {
            max = arr[i];
            pmax = true;
        }
        if (arr[i] > arr[i + 1]) {
            pmax = false;
        }
    }
    if (!pmax) return -1;
    return max;
}
