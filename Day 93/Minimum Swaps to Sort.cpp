/*
Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.
Example 2:

Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explaination:
swap 10 with 3 and swap 19 with 5.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minSwaps() which takes the nums as input parameter and returns an integer denoting the minimum number of swaps required to sort the array. If the array is already sorted, return 0. 


Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ n ≤ 105
1 ≤ numsi ≤ 106
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int, int>> v;
	    int count = 0;
	    
	    for (int i = 0; i < nums.size(); i++) {
	        v.push_back({nums[i], i});
	    }
	    sort(v.begin(), v.end());
	    
	    for (int i = 0; i < v.size(); i++) {
	        int sorted = v[i].second;
	        if (sorted == i) {
	            continue;
	        }
	        else {
	            swap(v[sorted], v[i]);
	            count++;
	            i--;
	        }
	    }
	    
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
