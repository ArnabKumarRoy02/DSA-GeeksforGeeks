/*
Given two sorted arrays A and B of size M and N respectively. Each array may have some elements in common with the other array. Find the maximum sum of a path from the beginning of any array to the end of any of the two arrays. We can switch from one array to another array only at the common elements.Both the arrays are sorted.
Note: Only one repeated value is considered in the valid path sum.


Example 1:

Input:
M = 5, N = 4
A[] = {2,3,7,10,12}
B[] = {1,5,7,8}
Output: 35
Explanation: The path will be 1+5+7+10+12
= 35.

Example 2:

Input:
M = 3, N = 3
A[] = {1,2,3}
B[] = {3,4,5}
Output: 15
Explanation: The path will be 1+2+3+4+5=15.

Your Task:
You don't need to read input or print anything. Complete the function max_path_sum() which takes the two arrays A and B along with their sizes M and N as input parameters. It returns the maximum path sum.


Expected Time Complexity: O(M + N)
Expected Auxiliary Space: O(1)


Constraints:
1 <= M,N <= 104
1 <= A[i], B[i] <= 104
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int A[], int B[], int l1, int l2)
    {
        int i = 0, j = 0, sum1 = 0, sum2 = 0, result = 0;
        
        while (i < l1 && j < l2) {
            if (A[i] < B[j]) {
                sum1 += A[i];
                i++;
            }
            
            if (A[i] > B[j]) {
                sum2 += B[j];
                j++;
            }
            
            if (A[i] == B[j]) {
                result += max(sum1, sum2) + A[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        
        while (i < l1) {
            sum1 += A[i];
            i++;
        }
        while (j < l2) {
            sum2 += B[j];
            j++;
        }
        
        result += max(sum1, sum2);
        
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}


// } Driver Code Ends
