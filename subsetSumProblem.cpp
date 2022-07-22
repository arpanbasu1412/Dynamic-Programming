#include<bits/stdc++.h> 
using namespace std; 

//Problem Link : https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// w[] ==arr[]     W ==sum

class Solution{   
public:
    bool subsetSum(vector<int>& arr, int sum,vector<vector<bool>>& dp,int n){
        
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

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum + 1));
        for(int i =0;i<=n;i++){
            for(int j =0;j<=sum;j++){
                if(i==0) dp[i][j]=false;
                if(j==0) dp[i][j]=true;
            }
        } 
        return subsetSum(arr,sum,dp,n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    
        int N, sum;
        cout<<"Enter the Size of the array"<<endl;
        cin >> N;
        vector<int> arr(N);
        cout<<"Enter the elements of the Array"<<endl;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cout<<"Enter Sum"<<endl;
        cin >> sum;
        
        Solution ob;
        cout<<"If prints 1 == true and if prints 0 == false"<<endl;
        cout << ob.isSubsetSum(arr, sum) << endl;
    return 0; 
} 