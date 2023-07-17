/*
Given a set of numbers from 1 to N, each number is exactly present twice so 
there are N pairs. In the worst-case scenario, how many numbers X should be 
picked and removed from the set until we find a matching pair?

Input:
N = 1
Output:
2
Explanation:
When N=1 Then there is 
one pair and a matching 
pair can be extracted in 
2 Draws.
*/

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int find(int N){ 
        return N + 1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
