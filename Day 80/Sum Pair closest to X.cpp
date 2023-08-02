/*
Given a sorted array arr[] of size N and a number X, find a pair in array whose sum is closest to X.

Example 1:

Input:
N = 6, X = 54
arr[] = {10, 22, 28, 29, 30, 40}
Output: 22 30
Explanation: As 22 + 30 = 52 is closest to 54.

Example 2:

Input:
N = 5, X = 10
arr[] = {1, 2, 3, 4, 5}
Output: 4 5
Explanation: As 4 + 5 = 9 is closest to 10.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sumClosest() which takes arr[] of size n and x as input parameters and returns a list containing 2 integers denoting the required pair. If multiple pairs are possible return the largest sum pair.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
2 <= N <= 105
0 <= X <= 106
0 <= arr[i] <= 106
*/
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        int i = 0;
        int j = arr.size() - 1;
        vector<int> ans(2, -1);
        int diff = INT_MAX;
        
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (abs(x - sum) < diff) {
                diff = abs(x - sum);
                ans[0] = arr[i];
                ans[1] = arr[j];
            }
            
            if (sum < x) i++;
            else j--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
