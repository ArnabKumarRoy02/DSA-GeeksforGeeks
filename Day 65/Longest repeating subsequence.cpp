/*
Given string str, find the length of the longest repeating subsequence such that it can 
be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string str 
if and only if that ith character has different indices in A and B. For example, A = "xax" 
and B = "xax" then the index of first "x" must be different in the original string for A and B.

Input:
str = "axxzxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    vector<vector<int>> v(n + 1, vector<int> (n + 1, 0));
		    int i, j;
		    i = j = 1;
		    while (i <= n) {
		        j = 1;
		        while (j <= n) {
		            if ((str[i - 1] == str[j - 1]) && (i != j)) {
		                v[i][j] = 1 + v[i - 1][j - 1];
		            }
		            else {
		                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
		            }
		            j++;
		        }
		        i++;
		    }
		    int x = v[n][n];
		    return x;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
