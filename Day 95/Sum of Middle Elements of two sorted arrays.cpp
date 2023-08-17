/*
Given 2 sorted arrays Ar1 and Ar2 of size N each. Merge the given arrays and find the sum of the two middle elements of the merged array.

 

Example 1:

Input:
N = 5
Ar1[] = {1, 2, 4, 6, 10}
Ar2[] = {4, 5, 6, 9, 12}
Output: 11
Explanation: The merged array looks like
{1,2,4,4,5,6,6,9,10,12}. Sum of middle
elements is 11 (5 + 6).
 

Example 2:

Input:
N = 5
Ar1[] = {1, 12, 15, 26, 38}
Ar2[] = {2, 13, 17, 30, 45}
Output: 32
Explanation: The merged array looks like
{1, 2, 12, 13, 15, 17, 26, 30, 38, 45} 
sum of middle elements is 32 (15 + 17).
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findMidSum() which takes  ar1, ar2 and n as input parameters and returns the sum of middle elements. 

 

Expected Time Complexity: O(log N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 103
1 <= Ar1[i] <= 106
1 <= Ar2[i] <= 106
*/
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
        vector<int> a(ar1, ar1 + n);
        vector<int> b(ar2, ar2 + n);
        
        a.insert(a.end(), b.begin(), b.end());
        sort(a.begin(), a.end());
        
        int size = a.size() - 1;
        return {a[size / 2] + a[size / 2 + 1]};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
