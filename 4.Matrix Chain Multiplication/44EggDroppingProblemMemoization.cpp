#include<bits/stdc++.h>
using namespace std;

// Enter Number of Eggs and Floors : 
// 2 10
// The minimum number of attempts we need in order to find the critical floor is 4

class Solution
{
    
    public:
    int dp[201][201];
    
    int solve(int n, int k)
    {
        if(k==1||k==0) return k;
        if(n==1) return k;
        
        if(dp[n][k] != -1) return dp[n][k];
        int mini = INT_MAX;
        for(int i = 1;i<=k;i++){
            int temp = 1+max(solve(n-1,i-1),solve(n,k-i));
            mini = min(mini,temp);
        }
        return dp[n][k]=mini;
    }
    
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};

int main()
{
    
    //taking eggs and floors count
    int n, k;
    cout<<"Enter Number of Eggs and Floors : "<<endl;
    cin>>n>>k;
    Solution ob;
    //calling function eggDrop()
    cout<<"The minimum number of attempts we need in order to find the critical floor is "<<ob.eggDrop(n, k)<<endl;
    
    return 0;
}