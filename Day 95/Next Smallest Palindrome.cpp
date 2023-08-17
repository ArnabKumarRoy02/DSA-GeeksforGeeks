/*
Given a number, in the form of an array Num[] of size N containing digits from 1 to 9(inclusive). The task is to find the next smallest palindrome strictly larger than the given number.

Example 1:

Input:
N = 11
Num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2}
Output: 9 4 1 8 8 0 8 8 1 4 9
Explanation: Next smallest palindrome is
9 4 1 8 8 0 8 8 1 4 9
Example 2:

Input:
N = 5
Num[] = {2, 3, 5, 4, 5}
Output: 2 3 6 3 2
Explanation: Next smallest palindrome is
2 3 6 3 2
Your Task:
Complete the function generateNextPalindrome() which takes an array num, and a single integer n, as input parameters and returns an array of integers denoting the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= Num[i] <= 9
*/
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	bool isGreater(vector<int> &arr, int num[], int n) {
	    for (int i = 0; i < n; i++) {
	        if (arr[i] < num[i]) return false;
	        if (arr[i] > num[i]) return true;
	    }
	    
	    return false;
	}
	
	vector<int> generateNextPalindrome(int num[], int n) {
	    vector<int> ans(n);
	    int l = 0, r = n - 1;
	    while (r > l) {
	        ans[r] = ans[l] = num[l];
	        l++;
	        r--;
	    }
	    ans[r] = num[r];
	    
	    if (isGreater(ans, num, n)) return ans;
	    
	    int carry = 1;
	    if (n % 2 == 1) {
	        ans[r]++;
	        if (ans[r] < 10) return ans;
	        ans[r] = 0;
	        carry = 1;
	        r--;
	        l++;
	    }
	    
	    while (r >= 0) {
	        ans[r] += carry;
	        ans[l] += carry;
	        if (ans[r] < 10) return ans;
	        ans[r] = ans[l] = 0;
	        carry = 1;
	        r--;
	        l++;
	    }
	    
	    if (carry == 1) {
	        ans.insert(ans.begin(), 1);
	        ans[ans.size() - 1] = 1;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
