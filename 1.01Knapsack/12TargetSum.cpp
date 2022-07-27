#include <bits/stdc++.h>
using namespace std;

// Enter Target Sum: 3
// Enter size of the array: 4
// Enter array elements:1 2 3 1
// The number of ways found is 2

int subsetSum(vector<int>& nums, int n, int sum)
    {
        // Initializing the matrix
        int dp[n + 1][sum + 1];
        // Initializing the first value of matrix
        dp[0][0] = 1;
        for (int i = 1; i <= sum; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                // if the value is greater than the sum
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]; 
                else
                      dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
    
int targetSum(int n, int target, vector<int>& nums) {
    // int n = nums.size();
    int sum=0;        
    for(int i=0;i<n;i++)
            sum+=nums[i];
    
    if(sum<target || (sum-target)%2!=0)   return 0;
    
        int reqSum=(sum-target)/2;
        return subsetSum(nums,n,reqSum);
}

int main() {

  int target,n;
  cout<<"Enter Target Sum: ";
  cin>>target;
  cout<<"Enter size of the array: ";
  cin>>n;
  vector<int> nums(n);
  cout<<"Enter array elements:";
  for (int i = 0; i < n; i++)
  {
    cin>>nums[i];
  }
        
  cout<<"The number of ways found is " <<targetSum(n,target,nums);
}