/*
Given a function that takes a binary string. The task is to return the longest 
size of contiguous substring containing only ‘1’.

Input:
The first line of input contains an integer T denoting the no of test cases.Then 
T test cases follow. Each test case contains a string S.

Output:
For each test case return the maximum length of required sub string.

Constraints: 
1<=T<=100
1<=|string length|<=104

Example:
Input:
2
110
11101110
Output:
2
3
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int maxlength(string s);
int main()
{
int t;
cin>>t;
while(t--)
{
string s;
cin>>s;
cout<<maxlength(s)<<endl;
}
return 0;
}

// } Driver Code Ends


int maxlength( string s)
{
    int count = 0;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1')
            count++;
        else {
            res = max(res, count);
            count = 0;
        }
    }
    res = max(res, count);
    return res;
}
