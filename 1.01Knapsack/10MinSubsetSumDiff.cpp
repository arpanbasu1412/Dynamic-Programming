#include <bits/stdc++.h>
using namespace std;


// `````````````I\0````````````````
// Enter the size of the Array:
// 4
// Enter the elements of the Array:
// 1 6 11 5
// The absolute min value of two subset is 1


class Solution{

  public:
  int subsetSum(int arr[], int sum,vector<vector<bool>>& dp,int n){
 
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
        int ind=0;
        for(int i =0;i<=sum/2;i++){
            if(dp[n][i]==true) ind = i;
        }
        return (sum-(2*ind));
        
    }
	int minDifference(int arr[], int n)  { 
	    int range=0;
	    for(int i=0;i<n;i++){
	        range = range + arr[i];
	    }
        vector<vector<bool>> dp(n+1, vector<bool>(range + 1));
        for(int i =0;i<=n;i++){
            for(int j =0;j<=range;j++){
                if(i==0) dp[i][j]=false;
                if(j==0) dp[i][j]=true;
            }
        } 
	    return subsetSum(arr,range,dp,n);	    
	} 
};


int main() 
{ 
    int n;
    cout<<"Enter the size of the Array:"<<endl;
    cin >> n;
    int a[n];
    cout<<"Enter the elements of the Array:"<<endl;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    Solution ob;
    cout << "The absolute min value of two subset is "<<ob.minDifference(a, n) << "\n";
	     
    return 0;
}