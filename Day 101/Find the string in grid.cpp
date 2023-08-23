/*
Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down, and 4 diagonal directions.

Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions starting from the same coordinates, the list should contain the coordinates only once. 

Example 1:

Input: 
grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output: 
{{0,0}}
Explanation: 
From (0,0) we can find "abc" in horizontally right direction.
Example 2:

Input: 
grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
word = "abe"
Output: 
{{0,0},{0,2},{1,0}}
Explanation: 
From (0,0) we can find "abe" in right-down diagonal. 
From (0,2) we can find "abe" in left-down diagonal. 
From (1,0) we can find "abe" in horizontally right direction.
Your Task:
You don't need to read or print anything, Your task is to complete the function searchWord() which takes grid and word as input parameters and returns a list containing the positions from where the word originates in any direction. If there is no such position then returns an empty list.

Expected Time Complexity: O(n*m*k) where k is constant
Expected Space Complexity: O(1)

Constraints:
1 <= n <= m <= 50
1 <= |word| <= 15
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool find(vector<vector<char>> &grid,string word,int row,int col)
    {
        int n = grid.size(), m = grid[0].size();
        
        vector<pair<int,int>> directions={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        for (int i = 0; i < 8; i++) {
            int idx = 0, nrow = row, ncol = col;
            int delrow = directions[i].first;
            int delcol = directions[i].second;
                
            while (nrow>=0 && nrow<n && ncol>=0 && ncol<m && idx<word.size() && grid[nrow][ncol]==word[idx]) {
                nrow+=delrow;  ncol+=delcol;   
                idx++;
            } 
            
            if(word.size()==idx) return true;
        }
        
        return false;    
    }
	
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
        vector<vector<int>> result;
    
        int n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == word[0] && find(grid,word,i,j)) {
                   result.push_back({i,j});
                }
            }
        }
   
        return result;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends
