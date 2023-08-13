/*
Given a string str of length N which consists of only 0, 1 or 2s, count the number of substring which have equal number of 0s, 1s and 2s.
 

Example 1:

Input: str = “0102010”
Output: 2
Explanation: Substring str[2, 4] = “102” and
substring str[4, 6] = “201” has equal number
of 0, 1 and 2 
Example 2:

Input: str = “11100022”
Output: 0
Explanation: There is no substring with
equal number of 0 , 1 and 2.

Your Task:  
You don't need to read input or print anything.Your task is to complete the function getSubstringWithEqual012() which takes a single string str as input and returns the answer.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 105
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        unordered_map<string, int> mp;
        string key = "0#0";
        
        mp[key] = 1;
        int a = 0, b = 0, c = 0;
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '0') a++;
            else if (str[i] == '1') b++;
            else if (str[i] == '2') c++;
            string key = to_string(b - a) + "#" + to_string(c - b);
            if (mp.find(key) != mp.end())
                count += mp[key];
            mp[key]++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends
