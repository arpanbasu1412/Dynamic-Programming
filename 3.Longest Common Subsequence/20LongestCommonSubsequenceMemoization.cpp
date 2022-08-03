#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-common-subsequence/

// Enter Two Strings : 
// AGGTAB GXTXAYB
// Length of LCS is 4

int dp[1001][1001];

int lcs(string &X,string &Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if(dp[m][n]!=-1)
        return dp[m][n];

    if (X[m-1] == Y[n-1])
        return dp[m][n] = 1 + lcs(X, Y, m-1, n-1);
    else
        return dp[m][n] = max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

int longestCommonSubsequence(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    memset(dp,-1,sizeof(dp));
    return lcs( X, Y, m, n) ;
}


int main()
{
	// string X = "AGGTAB";
	// string Y = "GXTXAYB";
    string X,Y;
    cout<<"Enter Two Strings : "<<endl;
    cin>>X>>Y;
	cout<<"Length of LCS is "<< longestCommonSubsequence(X,Y);
	
	return 0;
}

