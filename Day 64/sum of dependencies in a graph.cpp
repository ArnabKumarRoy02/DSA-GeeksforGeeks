/*
Given a directed graph with V nodes and E edges. If there is an edge from u to v then u depends on v.
Find out the sum of dependencies for every node. Duplicate edges should be counted as separate edges.

Input:
V=4
E=4
Edges={ {0,2},{0,3},{1,3},{2,3} }

Output:
4
Explanation:
For the graph, A depends
on C and D i.e. 2, B depends on D i.e.
1, C depends on D i.e. 1
and D depends on none.
Hence answer -> 0 + 1 + 1 + 2 = 4
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sumOfDependencies(vector<int> adj[], int V) {
        int ans = 0;
        for (int i = 0; i < V; i++)
            ans += adj[i].size();
            
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<int> v[N];
        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            v[x].push_back(y);
        }
        Solution ob;
        cout << ob.sumOfDependencies(v, N) << "\n";
    }
}
// } Driver Code Ends
