/*
Given a string S consisting of lowercase Latin Letters. Return the first non-repeating 
character in S. If there is no non-repeating character, return '$'.

Example 1:

Input:
S = hello
Output: h
Explanation: In the given string, the
first character which is non-repeating
is h, as it appears first and there is
no other 'h' in the string.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S) {
        vector<int> arr(26, 0);
        int min = INT_MAX;
        char ans;
        
        for (int i = 0; i < S.length(); i++) {
            arr[S[i] - 'a']++;
        }
        
        for (int i = 0; i < S.length(); i++) {
            if (arr[S[i] - 'a'] == 1) {
                return S[i];
            }
        }
        return '$';
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends
