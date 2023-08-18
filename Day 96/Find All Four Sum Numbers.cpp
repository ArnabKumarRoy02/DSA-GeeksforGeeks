/*
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 
Explanation: Sum of 0, 0, 1, 2 is equal
to K.
Example 2:

Input:
N = 7, K = 23
A[] = {10,2,3,4,5,7,8}
Output: 2 3 8 10 
        2 4 7 10 
        3 5 7 8 
Explanation: Sum of 2, 3, 8, 10 = 23,
sum of 2, 4, 7, 10 = 23 and sum of 3,
5, 7, 8 = 23.
Your Task:
You don't need to read input or print anything. Your task is to complete the function fourSum() which takes the array arr[] and the integer k as its input and returns an array containing all the quadruples in a lexicographical manner. Also note that all the quadruples should be internally sorted, ie for any quadruple [q1, q2, q3, q4] the following should follow: q1 <= q2 <= q3 <= q4.  (In the output each quadruple is separate by $. The printing is done by the driver's code)

Expected Time Complexity: O(N3).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= N <= 100
-1000 <= K <= 1000
-100 <= A[] <= 100
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> res;
        int n = arr.size();
        
        if (arr.empty()) return res;
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int l = k - arr[j] - arr[i];
                int f = j + 1;
                int r = n - 1;
                
                while (f < r) {
                    int two = arr[f] + arr[r];
                    if (two < l) f++;
                    else if (two > l) r--;
                    else {
                        vector<int> four(4, 0);
                        four[0] = arr[i];
                        four[1] = arr[j];
                        four[2] = arr[f];
                        four[3] = arr[r];
                        res.push_back(four);
                        
                        while (f < r && arr[f] == four[2]) f++;
                        while (f < r && arr[r] == four[3]) r--;
                    }
                }
                
                while (j + 1 < n && arr[j + 1] == arr[j]) j++;
            }
            while (i + 1 < n && arr[i + 1] == arr[i]) i++;
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
