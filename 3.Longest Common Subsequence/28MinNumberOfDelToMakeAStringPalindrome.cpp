#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// Enter String : 
// aebcbda
// Length of The longest Palindromic Subsequence is 2
// Explanation: We'll remove 'e' and
// 'd' and the string become "abcba".


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

int minDeletions(string X) {
    string Y = X;
    reverse(Y.begin(),Y.end());
    int m = X.size();
    int n = Y.size();
    memset(dp,-1,sizeof(dp));
    return ( m - lcs( X, Y, m, n) ) ;
}


int main()
{
    string X;
    cout<<"Enter String : "<<endl;
    cin>>X;
	cout<<"Length of The longest Palindromic Subsequence is "<< minDeletions(X);
	
	return 0;
}

