/*
Given an unsorted array arr of size N, rearrange the elements of array such that number at 
the odd index is greater than the number at the previous even index. The task is to complete 
the function formatArray() which will return formatted array.

NOTE:
If the returned array formed is according to rules, 1 will be printed else 0 will be printed.

Example 1:

Input:
n = 5
arr[] = {5, 4, 3, 2, 1}

Output:
1
Explanation:
The given array after modification
will be as such: 4 5 2 3 1.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> formatArray(vector<int> a,int n);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		vector<int>  b;
		b=formatArray(a,n);
		int flag=1;
		if(b.size()==n){
			for(int i=1;i<n;i+=2)
				if(b[i]<b[i-1])
					flag=0;
			if(flag==0)
				cout<<"0\n";
			else{
				sort(a.begin(),a.end());
				sort(b.begin(),b.end());
				for(int i=0;i<n;i++){
					if(a[i]!=b[i])
						flag=0;
				}
				cout<<flag<<endl;
			}
		}
		else
			cout<<"0\n";
	}
}
// } Driver Code Ends


/*Complete the function below*/
vector<int> formatArray(vector<int> a,int n)
{
    return sort(a.begin(), a.end()), a;
}
