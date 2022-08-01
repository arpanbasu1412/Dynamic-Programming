#include <bits/stdc++.h>
using namespace std;

// Enter String :
// ababbbabbababa
// The fewest cuts needed for palindrome partitioning of the given string is 3
// Explaination: After 3 partitioning substrings 
// are "a", "babbbab", "b", "ababa".

class Solution{
public:
    bool isPalindrome(string &s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    int solve(string &str,int i ,int j,vector<vector<int>>& dp){
        if(i>=j) return dp[i][j]=0;
        if(isPalindrome(str,i,j)) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k = i;k<=j-1;k++){
            int temp = solve(str,i,k,dp)+solve(str,k+1,j,dp)+1;
            mini=min(mini,temp);
        }
        return dp[i][j]=mini;
    }

    int palindromicPartition(string str)
    {
        int N = str.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return solve(str,0,N-1,dp);
    }
};


int main(){
   
    string str;
    cout<<"Enter String :"<<endl;
    cin>>str;
    
    Solution ob;
    cout<<"The fewest cuts needed for palindrome partitioning of the given string is "<<ob.palindromicPartition(str)<<"\n";

    return 0;
}