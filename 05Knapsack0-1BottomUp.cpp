#include <bits/stdc++.h>
using namespace std;

// tabulation format is actually bottom-up

// `````````````I\0````````````````

// Enter the weight of the Knapsack:
// 10
// Enter the number of items:
// 5
// Enter weight and value for the item:
// 3 100
// Enter weight and value for the item:
// 6 30
// Enter weight and value for the item:
// 2 20
// Enter weight and value for the item:
// 7 150
// Enter weight and value for the item:
// 4 110
// Max Profit is 250

// int knapSack(int val[],int w[],int W,int n,vector<vector<int>> &dp){
//     if(n==0||W==0) return 0;
//     if(dp[W][n]!=-1) return dp[W][n];
//     if(w[n-1]<=W) return dp[W][n]=max(knapSack(val,w,W-w[n-1],n-1,dp)+val[n-1],knapSack(val,w,W,n-1,dp));
//     else if(w[n-1]>W) return dp[W][n]=knapSack(val,w,W,n-1,dp);
// }


// `````````Derived knapsackTopDown() by looking into Recursive Code`````````

int knapsackTopDown(int val[],int w[],int W,int n,vector<vector<int>> &dp){
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (w[j-1]<=i)
            {
                dp[i][j]=max(dp[i-w[j-1]][j-1]+val[j-1],dp[i][j-1]);
            }
            else if(w[j-1]>i){
                dp[i][j]=dp[i][j-1];
            }
            
        }
        
    }
    return dp[W][n];
}

int main()
{
    int n,W;
    cout<<"Enter the weight of the Knapsack:"<<endl;
    cin>>W;
    cout<<"Enter the number of items:"<<endl;
    cin>>n;
    int val[n],w[n];
    vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter weight and value for the item:"<<endl;
        cin>>w[i]>>val[i];
    }

    for (int i = 0; i <= W; i++)
    {
        dp[i][0]=0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[0][i]=0;
    }
    // knapsackTopDown(val,w,W,n,dp);

    cout<<"Max Profit is "<<knapsackTopDown(val,w,W,n,dp)<<endl;
    
    return 0;
}
