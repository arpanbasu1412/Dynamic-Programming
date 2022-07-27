#include <bits/stdc++.h>
using namespace std;

// Enter number of items in the Knapsack and weight limit of the Knapsack:
// 4 8
// Enter values of the items:
// 1 4 5 7
// Enter weights of the items:
// 1 3 4 5
// Max Profit we can get is 11

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
        for (int i = 0; i <= W; i++)
            dp[i][0]=0;
            
        for (int i = 0; i <= n; i++)
            dp[0][i]=0;
            
        for (int i = 1; i <= W; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (wt[j-1]<=i)
                {
                    dp[i][j]=max(dp[i-wt[j-1]][j]+val[j-1],dp[i][j-1]);
                }
                else if(wt[j-1]>i){
                    dp[i][j]=dp[i][j-1];
                }
                
            }
            
        }
        return dp[W][n];
    }
};



int main(){
    
    int N, W;
    cout<<"Enter number of items in the Knapsack and weight limit of the Knapsack:"<<endl;
    cin>>N>>W;
    int val[N], wt[N];
    cout<<"Enter values of the items:"<<endl;
    for(int i = 0;i < N;i++)
        cin>>val[i];
        cout<<"Enter weights of the items:"<<endl;
    for(int i = 0;i < N;i++)
        cin>>wt[i];
    
    Solution ob;
    cout<<"Max Profit we can get is "<<ob.knapSack(N, W, val, wt)<<endl;

    return 0;
}