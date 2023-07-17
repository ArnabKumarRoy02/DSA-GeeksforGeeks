/*
Given an array of size n which contains all elements occurring in multiples of K, 
except one element which doesn't occur in multiple of K. Find that unique element.

Input : 
n = 7, k = 3
arr[] = {6, 2, 5, 2, 2, 6, 6}
Output : 
5
Explanation:
Every element appears 3 times except 5.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int findUnique(int a[], int n, int k) {
        map<int,int>hash;
        for(int i=0;i<n;i++) {
            hash[a[i]]++;
        }
        for(auto it : hash) {
            if(it.second%k!=0) {
                return it.first;
            }
        }
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        cout << obj.findUnique(a, n, k) << endl;
    }
}
// } Driver Code Ends
