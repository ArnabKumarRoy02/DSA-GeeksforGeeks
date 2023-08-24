/*
Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of all the occurences of pattern string in the text string. For printing, Starting Index of a string should be taken as 1.

Example 1:

Input:
S = "batmanandrobinarebat", pat = "bat"
Output: 1 18
Explanation: The string "bat" occurs twice
in S, one starts are index 1 and the other
at index 18. 
â€‹Example 2:

Input: 
S = "abesdu", pat = "edu"
Output: -1
Explanation: There's not substring "edu"
present in S.

Your Task:
You don't need to read input or print anything. Your task is to complete the function search() which takes the string S and the string pat as inputs and returns an array denoting the start indices (1-based) of substring pat in the string S. 


Expected Time Complexity: O(|S|*|pat|).
Expected Auxiliary Space: O(1).


Constraints:
1<=|S|<=105
1<=|pat|<|S|
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int> res;
            int k, j;
            bool flag = 0;
            
            for (int i = 0; i < txt.size(); i++) {
                k = 0;
                j = i;
                
                while (k < pat.size()) {
                    if (txt[j] == pat[k] && j < txt.size()) {
                        if (k == pat.size() - 1) {
                            flag = 1;
                            res.push_back(i + 1);
                        }
                        k++;
                        j++;
                    }
                    else {
                        break;
                    }
                }
            }
            
            if (flag == 0)
                res.push_back(-1);
                
            return res;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
