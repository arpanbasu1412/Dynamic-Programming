#include <bits/stdc++.h>
using namespace std;

// Enter size
// 3
// Enter coin denominations
// 1 2 5
// Enter amount_required
// 11
// Minimum number of coins required is 3
// Explanation: 11 = 5 + 5 + 1

int CoinChange1(int coin[], int n, int amount_required, vector<vector<int>> &dp)
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= amount_required; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] =min( 
                    dp[i - 1][j],
                    1+dp[i][j - coin[i - 1]]
                    );
            }
            else if (coin[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount_required];
}
int main()
{
    printf("Enter size\n");
    int n;
    scanf("%d", &n);
    int coin[n];
    printf("Enter coin denominations\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coin[i]);
    }
    printf("Enter amount_required\n");
    int amount_required;
    scanf("%d", &amount_required);
    //if we take long long dp matrix
    //we can use INT_MAX instead of INT_MAX-1
    //as overflow wont occur in case of long long
    vector<vector<int>> dp(n + 1, vector<int>(amount_required + 1));
    //when size of array is zero
    //infinite coins will be required to reach amount
    for (int i = 0; i <=amount_required ; i++)
        dp[0][i] = INT_MAX-1;
    //when sum is zero,then 0 coins are required
    for (int i = 0; i <=n; i++)
        dp[i][0] = 0;
    for(int j=1;j<=amount_required;j++)
    {
        if(j%coin[0]==0)
        {
            dp[1][j]=j/coin[0];
        }
        else
        {
            dp[1][j]=INT_MAX-1;
        }
    }
    printf("Minimum number of coins required is %d\n", CoinChange1(coin, n, amount_required, dp));
    return 0;
}