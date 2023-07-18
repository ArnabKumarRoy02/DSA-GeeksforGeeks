/*
Count the numbers between 1 to N containing 4 as a digit.

Input:
N = 9
Output:
1
Explanation:
4 is the only number between 1 to 9
which contains 4 as a digit.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countNumberswith4(int N) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            int num = i;
            int flag = 0;
            while (num > 0) {
                int rem = num % 10;
                if (rem == 4) {
                    flag = 1;
                }
                num = num / 10;
            }
            
            if (flag == 1) {
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countNumberswith4(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
