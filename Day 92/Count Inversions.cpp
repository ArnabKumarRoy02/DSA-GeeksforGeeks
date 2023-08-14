/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.
Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.
Your Task:
You don't need to read input or print anything. Your task is to complete the function inversionCount() which takes the array arr[] and the size of the array as inputs and returns the inversion count of the given array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 5*105
1 ≤ arr[i] ≤ 1018
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int count=0;
    void merge(long long arr[],long long low, long long mid, long long high){
        long long size1 = mid-low+1;
        long long size2 = high-mid;
        long long L[size1],R[size2];
        for(long long i=0;i<size1;i++){
            L[i]=arr[i+low];
        }
        for(long long i=0;i<size2;i++){
            R[i]=arr[i+mid+1];
        }
        long long i=0,j=0,k=low;
        while(i<size1&&j<size2){
            if(L[i]<=R[j]) arr[k++]=L[i++];
            // else arr[k++]=R[j++];        
            else{
                arr[k++]=R[j++];
                count+=size1-1-i+1;
            }
        }
        while(i<size1) arr[k++]=L[i++];
        while(j<size2) arr[k++]=R[j++];
    }
    void mergeSort(long long arr[],long long low,long long high){
        if(low<high){
            long long mid=low+(high-low)/2;
            mergeSort(arr,low,mid);
            mergeSort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,0,N-1);
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
