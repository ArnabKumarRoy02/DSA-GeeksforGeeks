/*
You are given an undirected graph of N nodes and M edges. Return 1 if the graph is a tree, else return 0.

Note: The input graph can have self-loops and multiple edges.

Example 1:

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [1, 3]]
Output: 1
Explanation: Every node is reachable
and the graph has no loops, so it is a tree
Example 2:

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [2, 0]]
Output: 0
Explanation: 3 is not connected to any
node and there is a loop 0->1->2->0, so
it is not a tree.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function isTree() which takes the integer N (the number nodes in the input graph) and an adjacency list representing the graph as input parameters and returns 1 if the input graph is a tree, else 0.

 

Expected Time Complexity: O(|N| + |M|)
Expected Auxiliary Space: O(|N|)

 

Constraints:
1 <= N <= 2*10^5
1 <= M <= 2*10^5
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    void dfs(int n, int s, vector<bool> &visited, vector<int> adj[]) {
        if (visited[s]) return;
        visited[s] = true;
        for (auto i: adj[s]) {
            dfs(n, i, visited, adj);
        }
    }
    
    int isTree(int n, int m, vector<vector<int>> &adj) {
        vector<int>adjl[n];
        for (auto i: adj) {
            adjl[i[0]].push_back(i[1]);
            adjl[i[1]].push_back(i[0]);
        }
        
        vector<bool> visited(n, false);
        dfs(n, 0, visited, adjl);
        
        if (find(visited.begin(), visited.end(), false) == visited.end() && m == n - 1) return 1;
        else return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> adj(m, vector<int>(2));
        Matrix::input(adj,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, adj);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
