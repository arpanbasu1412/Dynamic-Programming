#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// Enter String : 
// abcd
// Minimum Insertion Steps to Make a String Palindrome is 3
// Explanation: Inserted character marked
// with bold characters in dcbabcd


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

int minInsertions(string X) {
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
	cout<<"Minimum Insertion Steps to Make a String Palindrome is "<< minInsertions(X);
	
	return 0;
}

