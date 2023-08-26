/*
Given a string s, remove all its adjacent duplicate characters recursively. 

Note: For some test cases, the resultant string would be an empty string. In that case, the function should return the empty string only.

Example 1:

Input:
S = "geeksforgeek"
Output: "gksforgk"
Explanation: 
g(ee)ksforg(ee)k -> gksforgk

Example 2:

Input: 
S = "abccbccba"
Output: ""
Explanation: 
ab(cc)b(cc)ba->abbba->a(bbb)a->aa->(aa)->""(empty string)

Your Task:
You don't need to read input or print anything. Your task is to complete the function rremove() which takes the string S as input parameter and returns the resultant string.


Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)


Constraints:
1<=|S|<=105
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        string temp="";
        bool flag = false;
        
        for (int i = 0; i < s.length() ; i++) {
            if (s[i] == s[i+1]) {
                flag = true;
                while (s[i] == s[i+1]) {
                    i++;
                }
            }
            
            else {
                temp.push_back(s[i]);
            }
        }
        
        if(!flag) return temp;
        
        return rremove(temp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends
