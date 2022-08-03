#include <bits/stdc++.h>
using namespace std;

// Enter Two Strings : 
// AGGTAB GXTXAYB
// LCS is GTAB
// Length of Longest Common Subsequence is 4

int dp[1001][1001];

int PrintLongestCommonSubsequence(string &X,string &Y, int m, int n)
{
    string s;
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

    // for printing longest common subsequence
    int i=m,j=n;
    while(i>0 && j>0){    // if any of this i and j becomes 0 means one string is empty 
        if(X[i-1]==Y[j-1]){
            s+=X[i-1];    //if character matches then add that to result string and move diagonally up
            i--;j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j])j--;    // else find the max of up and right position of dp table and move accordingly to up or left
            else i--;
        }
    }
    reverse (s.begin(),s.end());    // reverse the string as we started from last
    cout<<"LCS is "<<s<<endl;

    return dp[m][n];
}

int longestCommonSubseq(string X, string Y, int m, int n)
{
        memset(dp,-1,sizeof(dp));
        return PrintLongestCommonSubsequence( X, Y, m, n) ;
}


int main()
{
	// string X = "AGGTAB";
	// string Y = "GXTXAYB";
    string X,Y;
    cout<<"Enter Two Strings : "<<endl;
    cin>>X>>Y;
    int m = X.size();
    int n = Y.size();
	cout<<"Length of Longest Common Subsequence is "<< longestCommonSubseq(X,Y,m,n);
	
	return 0;
}

