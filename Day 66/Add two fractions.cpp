/*
You are given four numbers num1, den1, num2, and den2. You need to find (num1/den1)+(num2/den2)
and output the result in the form of (numx/denx).

Input Format:
The first line of input contains an integer T denoting the number of test cases . Then T test 
cases follow . Each test case contains four integers num1, den1, num2, den2 respectively .

Output Format:
For each test case, in a new line,  output will be the fraction in the form a/b where the 
fraction denotes the sum of the two given fractions in reduced form.

Your Task:
Since this is a function problem, you don't need to worry about the testcases. Your task is to 
complete the function addFraction  which adds the two fractions and prints the resulting fraction. 
The function takes four arguments num1, den1, num2, den2 where num1, num2 denotes the numerators of 
two fractions and den1, den2 denotes their denominators.
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


void addFraction(int num1, int den1, int num2,
                 int den2);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b,c,d,resultNum,resultDen;
        cin>>a>>b>>c>>d;
        addFraction(a,b,c,d);

    }
}

// } Driver Code Ends


/*You are required to complete this function*/
void addFraction(int num1, int den1, int num2,int den2) {
    int up = (num1 * den2) + (num2 * den1);
    int down = den1 * den2;
    int common = __gcd(up, down);
    up = up/common;
    down = down/common;
    cout << up << "/" << down << endl;
}
