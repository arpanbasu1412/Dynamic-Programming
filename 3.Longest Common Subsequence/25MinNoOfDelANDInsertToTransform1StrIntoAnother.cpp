#include <bits/stdc++.h>
using namespace std;

// Enter Two Strings : 
// heap pea
// Number of Deletion is 2 
// Number of Insertion is 1
// Minimum number of deletions and insertions to transform one string into another is 3 

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

int minOperations(string X, string Y) 
{ 
    int m = X.size();
    int n = Y.size();
    memset(dp,-1,sizeof(dp));
    int temp = lcs( X, Y, m, n);
    int del_no = m-temp;
    int insert_no = n-temp;
    cout<<"Number of Deletion is "<<del_no<<endl;
    cout<<"Number of Insertion is "<<insert_no<<endl;
    return del_no+insert_no;
} 

int main()
{
	// string X = "heap";
	// string Y = "pea";
    string X,Y;
    cout<<"Enter Two Strings : "<<endl;
    cin>>X>>Y;
	cout<<"Minimum number of deletions and insertions to transform one string into another is "<< minOperations(X,Y);
	
	return 0;
}