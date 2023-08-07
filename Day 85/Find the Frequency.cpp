/*
Given a vector of N positive integers and an integer X. The task is to find the frequency of X in vector.

Example 1:

Input:
N = 5
vector = {1, 1, 1, 1, 1}
X = 1
Output: 
5
Explanation: Frequency of 1 is 5.
Your Task:
Your task is to complete the function findFrequency() which should count the frequency of X and return it.
*/
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

/*Function to find frequency of x
* x : element whose frequency is to be found
* v : input vector
*/
int findFrequency(vector<int> v, int x){
    int k = 0;
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == x) {
            k++;
        }
    }
    
    return k;
}

//{ Driver Code Starts.
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    
	    // Declaring vector 
	    vector<int> v;
	        
	    // Taking vector element input
	    for(int i = 0;i<N;i++){
	        int k;
	        cin >> k;
	        v.push_back(k);
	    }
	    
	    // element whose frequency to be find
	    int x;
	    cin >> x;
	    cout << findFrequency(v, x) << endl;
	}
	
	return 0;
}
// } Driver Code Ends
