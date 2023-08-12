/*
Given an n-digit large number in form of string, check whether it is divisible by 7 or not. Print 1 if divisible by 7, otherwise 0.


Example 1:

Input: num = "8955795758"
Output: 1
Explanation: 8955795758 is divisible
by 7.
Example 2:

Input: num = "1000"
Output: 0
Explanation: 1000 is not divisible
by 7.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isdivisible7â€‹() which takes the string num as inputs and returns the answer.


Expected Time Complexity: O(|num|)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ |num| ≤ 105
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int isdivisible7(string num){
        int rem = 0;
        
        for (int i = 0; i < num.length(); i++) {
            rem = ((rem * 10) + (num[i] - '0')) % 7;
        }
        
        return rem == 0 ? 1:0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isdivisible7(s) << endl;
    }
    return 0;
}
// } Driver Code Ends
