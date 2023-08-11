/*
Given two strings of lowercase alphabets and a value K, your task is to complete the given function which tells if  two strings are K-anagrams of each other or not.

Two strings are called K-anagrams if both of the below conditions are true.
1. Both have same number of characters.
2. Two strings can become anagram by changing at most K characters in a string.

Example:

Input:
str1 = "fodr", str2="gork"
k = 2
Output:
1
Explanation: Can change fd to gk
Your Task:
Since this is a function problem, you don't need to take any input. Just complete the given function areKAnagrams that returns true if the strings can be turned into K-anagrams, else return false.

Constraints:
1 ≤ length of String ≤ 105
1 ≤ K ≤ length of String
*/
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        unordered_map<char, int> mp;
        int ans = 0;
        
        if (str1.size() != str2.size()) return false;
        for (int i = 0; i < str1.size(); i++) {
            mp[str1[i]]++;
        }
        for (int i = 0; i < str2.size(); i++) {
            mp[str2[i]]--;
        }
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans += abs(it->second);
        }
        
        return ans <= 2*k;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}
// } Driver Code Ends
