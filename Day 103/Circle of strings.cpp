/*
Given an array of lowercase strings A[] of size N, determine if the strings can be chained together to form a circle.
A string X can be chained together with another string Y if the last character of X is same as first character of Y. If every string of the array can be chained with exactly two strings of the array(one with the first character and second with the last character of the string), it will form a circle.

For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"


Example 1:

Input:
N = 3
A[] = { "abc", "bcd", "cdf" }
Output:
0
Explaination:
These strings can't form a circle 
because no string has 'd'at the starting index.
Example 2:

Input:
N = 4
A[] = { "ab" , "bc", "cd", "da" }
Output:
1
Explaination:
These strings can form a circle 
of strings.

Your Task:
You don't need to read input or print output. Your task is to complete the function isCircle() which takes the length of the array N and the array A as input parameters and returns 1 if we can form a circle or 0 if we cannot.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints: 
1 ≤ N ≤ 104
1 ≤ Length of strings ≤ 20
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    bool mark1[26]={false};
    void dfs(vector<int>&s,vector<int>adj[],bool mark[],int i) {
        mark[i]=true;
        for(auto x:adj[i])
        {
            if(!mark[x]) dfs(s,adj,mark,x);
        }
        s.push_back(i);
    }
    
    void dfs1(vector<int>adj1[],int i) {
        mark1[i]=true;
        for(auto x:adj1[i])
        {
            if(!mark1[x]) dfs1(adj1,x);
        }
       
    }
    
    int isCircle(int n, vector<string> a) {
        int indegree[26]={0};
        int outdegree[26]={0};
        vector<int>adj[26];
        for(int i=0;i<n;i++)
        {
            adj[a[i][0]-'a'].push_back(a[i][a[i].size()-1]-'a');
            indegree[a[i][a[i].size()-1]-'a']++;
            outdegree[a[i][0]-'a']++;
            
        }
        for(int i=0;i<26;i++)
        {
            if(indegree[i]!=outdegree[i]) return 0;
        }
        vector<int>s;
        bool mark[26]={false};
       for(int i=0;i<26;i++){
           
       if(outdegree[i]==0) continue;
        if(!mark[i]){
        dfs(s,adj,mark,i);
        }
       }
       vector<int>adj1[26];
       for(int i=0;i<n;i++)
        {
            adj1[a[i][a[i].size()-1]-'a'].push_back( a[i][0]-'a');
          
        }
     
       bool flag=true;
       
       for(int i=0;i<s.size();i++)
       {
          
           if(mark1[s[i]]==false)
           { 
                       if(flag==false) return 0;
                       flag=false;
                       dfs1(adj1,s[i]);

           }
           
       }
       return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends
