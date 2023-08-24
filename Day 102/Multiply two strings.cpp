/*
Given two numbers as strings s1 and s2. Calculate their Product.

Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers.

Example 1:

Input:
s1 = "0033"
s2 = "2"
Output:
66
Example 2:

Input:
s1 = "11"
s2 = "23"
Output:
253
Your Task: You don't need to read input or print anything. Your task is to complete the function multiplyStrings() which takes two strings s1 and s2 as input and returns their product as a string.

Expected Time Complexity: O(n1* n2)
Expected Auxiliary Space: O(n1 + n2); where n1 and n2 are sizes of strings s1 and s2 respectively.

Constraints:
1 ≤ length of s1 and s2 ≤ 103
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        vector<int>res(s1.size()+s2.size(),0);
        bool temp=true;
        
        if(s1[0]=='-'&&s2[0]=='-'){
            s1.erase(s1.begin(),s1.begin()+1);
            s2.erase(s2.begin(),s2.begin()+1);
        }
        
        else if(s1[0]=='-'||s2[0]=='-'){
            temp=!temp;
            if(s1[0]=='-'){
               s1.erase(s1.begin(),s1.begin()+1);
            }
            else if(s2[0]=='-'){
             s2.erase(s2.begin(),s2.begin()+1);  
            }
        }
      
        int i1=0;
        int i2=0;
        
        for(int i=s1.size()-1;i>=0;i--){
           int carry=0;
            int n1=s1[i]-'0';
            i2=0;
           for(int j=s2.size()-1;j>=0;j--){
              
               int n2=s2[j]-'0';
               int sum=n1*n2+carry+res[i1+i2];
               carry=sum/10;
               res[i1+i2]=sum%10;
               i2++;
           }
           if (carry > 0)
            res[i1 + i2] += carry;
            i1++;
        }
        int i = res.size() - 1;
        while (i>=0 && res[i] == 0)
        i--;
        if (i == -1)
        return "0";
        string s = "";
        while (i >= 0)
            s += to_string(res[i--]);
           
        if(!temp){
            s='-'+s;
        }
        return s;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends
