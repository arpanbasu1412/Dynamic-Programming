#include <bits/stdc++.h>
using namespace std;

// Enter Two Strings : 
// abcdefg adefgr
// Length of Longest Common Substring is 4

int dp[1001][1001];

int LongestCommonSubstring(string &X,string &Y, int m, int n)
{
    int maxi=0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
    
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
    
            else
                dp[i][j] = 0;

            maxi=max(maxi,dp[i][j]); 
        }
    }
    return maxi;
}

int longestCommonSubstr (string X, string Y, int m, int n)
{
        memset(dp,-1,sizeof(dp));
        return LongestCommonSubstring( X, Y, m, n) ;
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
	cout<<"Length of Longest Common Substring is "<< longestCommonSubstr(X,Y,m,n);
	
	return 0;
}

