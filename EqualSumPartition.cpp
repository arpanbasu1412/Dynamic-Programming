#include <bits/stdc++.h>
using namespace std;

// Enter the size of the array:4
// Enter the elements of the array:
// 1 5 11 5
// YES equal partiton is Possible

class Solution{
public:
    bool subsetSum(int arr[], int sum,int n)
    {
        vector<vector<bool>> dp(n+1, vector<bool>(sum + 1));
        for(int i =0;i<=n;i++){
            for(int j =0;j<=sum;j++){
                if(i==0) dp[i][j]=false;
                if(j==0) dp[i][j]=true;
            }
        }
        for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i-1]<=j)
                {
                    dp[i][j]=(dp[i-1][j] || dp[i-1][j-arr[i-1]]);
                }
                else{
                     dp[i][j]=dp[i-1][j];
                }          
            }     
        } 
        return dp[n][sum];
    }
    
    int equalPartition(int N, int arr[])
    {
        long sum = 0;
        for(int i =0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return 0;
        int target = sum/2;
        int ans=subsetSum(arr,target,N)?1:0;
        return ans;
    }
};


int main(){
    cout<<"Enter the size of the array:";
    int N;
    cin>>N;
    int arr[N];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i = 0;i < N;i++)
        cin>>arr[i];
    
    Solution ob;
    if(ob.equalPartition(N, arr))
        cout<<"YES equal partiton is Possible\n";
    else
        cout<<"NO equal partition is not Possible\n";

    return 0;
}
