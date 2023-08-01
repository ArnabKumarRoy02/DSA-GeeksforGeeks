/*
Find the first non-repeating element in a given array arr of N integers.
Note: Array consists of only positive and negative integers and not zero.

Example 1:

Input : arr[] = {-1, 2, -1, 3, 2}
Output : 3
Explanation:
-1 and 2 are repeating whereas 3 is 
the only number occuring once.
Hence, the output is 3. 
 

Example 2:

Input : arr[] = {1, 1, 1}
Output : 0

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function firstNonRepeating() that takes an array (arr), sizeOfArray (n), and returns the first non-repeating element. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 107
-1016 <= Ai <= 1016
{Ai !=0 }
*/
//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
    public:
    int firstNonRepeating(int arr[], int n) 
    { 
        map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (mp[arr[i]] == 1) {
                return arr[i];
            }
        }
        return -1;
    } 
  
};


//{ Driver Code Starts.

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.firstNonRepeating(arr,n)<<endl;
    }
}

// } Driver Code Ends
