#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

// Enter String : 
// axxzxy
// Length of LCS is 2

// Explanation:
// The given array with indexes looks like
// a x x z x y 
// 0 1 2 3 4 5

// The longest subsequence is "xx". 
// It appears twice as explained below.

// subsequence A
// x x
// 0 1  <-- index of subsequence A
// ------
// 1 2  <-- index of str 


// subsequence B
// x x
// 0 1  <-- index of subsequence B
// ------
// 2 4  <-- index of str 

// We are able to use character 'x' 
// (at index 2 in str) in both subsequences
// as it appears on index 1 in subsequence A 
// and index 0 in subsequence B.


int dp[1001][1001];

int lcs(string &X,string &Y, int m, int n)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1] && i!=j)
                dp[i][j] = dp[i - 1][j - 1] + 1;
 
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int LongestRepeatingSubsequence(string X) {
    string Y = X;
    int m = X.size();
    int n = Y.size();
    memset(dp,-1,sizeof(dp));
    return lcs( X, Y, m, n) ;
}


int main()
{
    string X;
    cout<<"Enter String : "<<endl;
    cin>>X;
	cout<<"Length of the longest repeating subsequence is "<< LongestRepeatingSubsequence(X);
	
	return 0;
}

