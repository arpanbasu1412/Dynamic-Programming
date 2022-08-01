#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
// https://leetcode.com/problems/palindrome-partitioning-ii/                             ****Accepted****

// Exception Test Cases for Leetcode
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

// Enter String :
// ababbbabbababa
// The fewest cuts needed for palindrome partitioning of the given string is 3
// Explaination: After 3 partitioning substrings 
// are "a", "babbbab", "b", "ababa".


int dp[2002][2002];
bool isPalin(string &s, int i, int j)
{
    if(i >= j ) 
        return dp[i][j] = 0;
    

    if(dp[i][j]  !=  -1)
        return dp[i][j];

    if(s[i]==s[j]) 
        return dp[i][j] = isPalin(s,i+1,j-1);

    return dp[i][j] = -1;
}

int palinPart(string &s, int i, int j)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (isPalin(s, i, j) == 0)
        return dp[i][j] = 0;

    int minm = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left = isPalin(s,i,k);
        if(left != 0)   continue;
        
        int temp =  palinPart(s, k+1, j) + 1;
        minm = min(minm, temp);
    }
    return dp[i][j] = minm;
}

int palindromicPartition(string &s)
{
    int n = s.size();
    memset(dp, -1, sizeof(dp));
    return palinPart(s, 0, s.size()-1);
}


int main(){
    string s;
    cout<<"Enter String :"<<endl;
    cin>>s;
    cout<<"The fewest cuts needed for palindrome partitioning of the given string is "<<palindromicPartition(s)<<"\n";
    return 0;
}