/*
Geek is very fond of patterns. Once, his teacher gave him a  pattern to solve.
He gave Geek an integer n and asked him to build a pattern.

Help Geek to build a pattern.

Input: 5

Output:

*********
 *******
  *****
   ***
    *
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
	
	void printTriangle(int n) {
	    for (int i = n; i >= 1; i--) {
	        for (int j = 0; j < n - i; j++) {
	            cout << " ";
	        }
	        for (int j = 0; j < (2*i) - 1; j++) {
	            cout << "*";
	        }
	        cout << endl;
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends
