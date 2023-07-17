/*
Given an array a[] of size N which contains elements from 0 to N-1, you need to 
find all the elements occurring more than once in the given array. Return the answer 
in ascending order.

Note: The extra space is only for the array to be returned.
Try and perform all operations within the provided array. 

Input:
N = 4
a[] = {0,3,1,2}
Output: -1
Explanation: There is no repeating element in the array.Therefore output is -1.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> ans;
        sort(arr, arr + n);
        for (int i = 0; i < n; i++) {
            if (arr[i] == arr[i + 1]) {
                ans.push_back(arr[i]);
                while (arr[i] == arr[i + 1]) {
                    i++;
                }
            }
        }
        if (ans.size() == 0) return {-1};
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
