/*
Given two arrays of integers A[] and B[] of size N and M, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

Example 1:

Input: N = 6, M = 4
A[] = {4, 1, 2, 1, 1, 2}
B[] = (3, 6, 3, 3)
Output: 1
Explanation: Sum of elements in A[] = 11
Sum of elements in B[] = 15, To get same 
sum from both arrays, we can swap following 
values: 1 from A[] and 3 from B[]
Example 2:

Input: N = 4, M = 4
A[] = {5, 7, 4, 6}
B[] = {1, 2, 3, 8}
Output: 1
Explanation: We can swap 6 from array 
A[] and 2 from array B[]
Your Task:
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function findSwapValues() that takes array A, array B, integer N, and integer M as parameters and returns 1 if there exists any such pair otherwise returns -1.

Expected Time Complexity: O(MlogM+NlogN).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N, M ≤ 106
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        int sumA = 0, sumB = 0;
        
        for (int i = 0; i < n; i++) sumA += A[i];
        for (int j = 0; j < m; j++) sumB += B[j];
        
        int tar = (sumA - sumB);
        
        if (tar % 2 != 0) return -1;
        tar = tar / 2;
        
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) mp[A[i]]++;
        
        for (int i = 0; i < m; i++) {
            if (mp[(tar + B[i])] > 0) return 1;
        }
             
        return -1;
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends
