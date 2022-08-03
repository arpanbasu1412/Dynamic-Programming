#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-common-supersequence/

// Enter Two Strings : 
// AGGTAB GXTXAYB
// Shortest Common Supersequence is AGXGTXAYB  
// Length of Shortest Common Supersequence is 9

int dp[1001][1001];
int PrintSCS(string &X,string &Y, int m, int n)
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
    

    int i=m,j=n;
    while(i>0 && j>0){   
        if(X[i-1]==Y[j-1]){
            s+=X[i-1];    
            i--;j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                s.push_back(Y[j - 1]);
                j--;   
            }
            else{
                s.push_back(X[i - 1]);
                i--;
            }
        }
    }
    
    while (i > 0)
    {
        s += X[i - 1];
        i--;
    }
    while (j > 0)
    {
        s += Y[j - 1];
        j--;
    }
    
    reverse (s.begin(),s.end());
    cout<<"Shortest Common Supersequence is "<<s<<endl;
    // return s;
    return ( (m+n) - dp[m][n] );
    
}

int shortestCommonSupersequenc(string X, string Y, int m, int n)
{
        memset(dp,-1,sizeof(dp));
        return PrintSCS( X, Y, m, n);
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
	cout<<"Length of Shortest Common Supersequence is "<< shortestCommonSupersequenc(X,Y,m,n);
	
	return 0;
}

