/*
Given a string consisting of lowercase letters, arrange all its letters in ascending order. 

Input:
S = "edcab"
Output: "abcde"
Explanation: characters are in ascending
order in "abcde".
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string sort(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << sort(s) << endl;
    }
return 0;
}




// } Driver Code Ends


string sort(string s){
    return sort(s.begin(), s.end()), s;
}
