#include<bits/stdc++.h>
using namespace std;

// Enter Number of Eggs and Floors : 
// 2 10
// The minimum number of attempts we need in order to find the critical floor is 4

class Solution
{
    
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        if(k==1||k==0) return k;
        if(n==1) return k;
        int mini = INT_MAX;
        for(int i = 1;i<=k;i++){
            int temp = 1+max(eggDrop(n-1,i-1),eggDrop(n,k-i));
            mini = min(mini,temp);
        }
        return mini;
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