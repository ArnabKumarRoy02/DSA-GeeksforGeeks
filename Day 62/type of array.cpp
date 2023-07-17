/*
You are given an array of size N having no duplicate elements. The array can be categorized into the following:
1.  Ascending
2.  Descending
3.  Descending Rotated
4.  Ascending Rotated
Your task is to return which type of array it is and the maximum element of that array.

Input :
N = 5 
A[] = { 2, 1, 5, 4, 3}
Output :
5 3
Explanation:
Descending rotated with maximum
element 5 
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  
    public:
    pair<long long, int> maxNtype(long long arr[], long long n)
    {
        pair<long long ,int>p;
        if(arr[0]<=arr[1]&&arr[1]<=arr[n-2]&&arr[n-2]<=arr[n-1]){
            p.second = 1;
        }
         else if(arr[0]>=arr[1]&&arr[1]>=arr[n-2]&&arr[n-2]>=arr[n-1]){
            p.second = 2;
        }
        else if(arr[0]<=arr[n-1]){
            p.second=3;
        }
        else{
            p.second=4;
        }
        
        sort(arr, arr+n);
        p.first = arr[n-1];
        
    
    return p;
    }

};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        pair<long long, int> pair = ob.maxNtype(arr, n);
        cout<<pair.first<<" "<<pair.second<<"\n";
    }
	return 0;
}
// } Driver Code Ends
