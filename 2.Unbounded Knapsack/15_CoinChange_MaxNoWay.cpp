#include <bits/stdc++.h>
using namespace std;

// Enter the number of amount and number of coins:
// 4 3
// Enter the coins:
// 1 2 3
// Total number of ways by which we can make the amount is 4 
// Explanation: Four Possible ways are:
// {1,1,1,1},{1,1,2},{2,2},{1,3}.

class Solution {
  public:
    long long int count(int coins[], int n, int amount) {

        // int n = coins.size();
        vector<vector<long long int>> dp(n + 1, vector<long long int>(amount + 1));
        for (int i = 0; i <=amount ; i++)
            dp[0][i] = 0;
        for (int i = 0; i <=n; i++)
            dp[i][0] = 1;
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j]+dp[i][j - coins[i - 1]];
                }
                else if (coins[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][amount];
    }
};


int main() {
   
    int amount,n;
    cout<<"Enter the number of amount and number of coins:"<<endl;
    cin >> amount >> n;
    int arr[n];
    cout<<"Enter the coins:"<<endl;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    Solution ob;
    cout << "Total number of ways by which we can make the amount is "<<ob.count(arr, n, amount) << endl;

    return 0;
}