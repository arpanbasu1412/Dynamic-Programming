#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

// Enter the Expression : T|T&F^T
// The number of ways we can parenthesize the expression so that the value of 
// expression evaluates to true is 4
int dp[201][201][2];
int parenthesis_count(string s,int i,int j,int isTrue)
{
    //Base Condition
    if (i > j)
        return false;
    if (i == j) {
        if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    //Main Logic
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int ans = 0;
    for (int k = i+1; k <=j-1 ; k=k+2)
    {
        int leftF, leftT, rightT, rightF;
        if (dp[i][k - 1][1] == -1)
            leftT = parenthesis_count(s, i, k - 1, 1);
             // Count no. of T in left partition
        else 
            leftT = dp[i][k - 1][1];
 
        if (dp[k + 1][j][1] == -1)
            rightT = parenthesis_count(s, k + 1, j, 1);
             // Count no. of T in right partition
        else
            rightT = dp[k + 1][j][1];

 
        if (dp[i][k - 1][0] == -1)
            // Count no. of F in left partition
            leftF = parenthesis_count(s, i, k - 1, 0);
        else
            leftF = dp[i][k - 1][0];
 
        if (dp[k + 1][j][0] == -1)
            // Count no. of F in right partition
            rightF = parenthesis_count(s, k + 1, j, 0);
        else
            rightF = dp[k + 1][j][0];



        if (s[k] == '&')
        {
            if (isTrue == 1)
                ans += leftT * rightT;
            else
                ans += leftF * rightF + leftT * rightF
                       + leftF * rightT;
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
                ans += leftT * rightT + leftT * rightF
                       + leftF * rightT;
            else
                ans = ans + leftF * rightF;
        }
        else if (s[k] == '^')
        {
            if (isTrue == 1)
                ans = ans + leftF * rightT + leftT * rightF;
            else
                ans = ans + leftT * rightT + leftF * rightF;
        }
        // dp[i][j][isTrue] = ans;
    }
    return dp[i][j][isTrue] = ans;
}

int main()
{
    // string s="T|T&F^T";
    string s;
    cout<<"Enter the Expression : ";
    cin>>s;
    int n = s.length();
    memset(dp, -1, sizeof(dp)); 
    // There are 4 ways
    // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
    // (T|((T&F)^T))
    cout <<"The number of ways we can parenthesize the expression so that the value of expression evaluates to true is " <<parenthesis_count(s, 0, n - 1, 1);
    return 0;
}