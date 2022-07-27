#include <bits/stdc++.h>
using namespace std;

// Enter the size of the Array(N):
// 8
// Enter the prize of all pieces of size smaller than N:
// 1 5 8 9 10 17 17 20
// The maximum value obtainable by cutting up the rod is 22  

class Solution{
  public:
    int cutRod(int price[], int n) {
        int wt[n];
        int W =n;
        for(int i =0;i<n;i++){
            wt[i]=i+1;
        }
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
                    dp[i][j]=max(dp[i-wt[j-1]][j]+price[j-1],dp[i][j-1]);
                }
                else if(wt[j-1]>i){
                    dp[i][j]=dp[i][j-1];
                } 
            }  
        }
        return dp[W][n];
    }
};


int main() {
   
    int n;
    cout<<"Enter the size of the Array(N):"<<endl;
    cin >> n;
    int a[n];
    cout<<"Enter the prize of all pieces of size smaller than N:"<<endl;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
        
    Solution ob;
    cout <<"The maximum value obtainable by cutting up the rod is "<<ob.cutRod(a, n) << endl;

    return 0;
}