/*
Given a String S. Find out which of the following basic C++ data types it represents and return it's size (in bytes).
The possible data types are:
1. Integer
2. Float
3. Double
4. Character

Input:
S=a
output:
1
Explanation:
The string clearly represents char 
and thus the size of char is displayed.
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User functiom template for C++

class Solution {
  public:
    int BasicDataType(string s) {
        const size_t i{ s.find( '.' )};
        return s.size() == 1 && !isdigit( s.front() ) ? 1 : i == -1 || s.size()-i < 7 ? 4 : 8;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.BasicDataType(S) << endl;
    }
}
// } Driver Code Ends
