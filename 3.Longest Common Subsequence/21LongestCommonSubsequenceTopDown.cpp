#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-common-subsequence/

// Enter Two Strings : 
// AGGTAB GXTXAYB
// Length of LCS is 4

int dp[1001][1001];

int lcs(string &X,string &Y, int m, int n)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
 
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
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

