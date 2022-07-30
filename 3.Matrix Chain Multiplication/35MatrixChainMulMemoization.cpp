#include <bits/stdc++.h>
using namespace std;

// Enter Size of the Array : 5
// Enter Elements of the Array : 
// 40 20 30 10 30
// The Min number of multiplication is 26000

class Solution{
public:

    int solve(int arr[],int i ,int j,vector<vector<int>>& dp){
        if(i>=j) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k = i;k<=j-1;k++){
            int temp = solve(arr,i,k,dp)+solve(arr,k+1,j,dp)+(arr[i-1]*arr[k]*arr[j]);
            if(temp<mini) mini=temp;
        }
        return dp[i][j]=mini;
    }

    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return solve(arr,1,N-1,dp);
    }
};

int main(){
    
    int N;
    cout<<"Enter Size of the Array : ";
    cin>>N;
    int arr[N];
    cout<<"Enter Elements of the Array : "<<endl;
    for(int i = 0;i < N;i++)
        cin>>arr[i];
    
    Solution ob;
    cout<<"The Min number of multiplication is "<<ob.matrixMultiplication(N, arr)<<endl;
    
    return 0;
}