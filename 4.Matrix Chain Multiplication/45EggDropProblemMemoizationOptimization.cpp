#include <bits/stdc++.h>
using namespace std;


// *****Another Approach:Using Binary Search*****
// https://leetcode.com/submissions/detail/763437291/
// https://leetcode.com/problems/super-egg-drop/submissions/

// Enter Number of Eggs and Floors :
// 2 10
// The minimum number of attempts we need in order to find the critical floor is 4

class Solution
{

public:
    int dp[201][201];

    int solve(int n, int k)
    {
        if (k == 1 || k == 0)
            return k;
        if (n == 1)
            return k;

        if (dp[n][k] != -1)
            return dp[n][k];
        int mn = INT_MAX;

        for (int f = 1; f <= k; f++)
        {
            //  int temp = 1+ max(  solve(n-1,f-1), solve(n,k-f) );
            // this above line can be optimised as
            int low = INT_MIN, high = INT_MIN;
            if (dp[n - 1][f - 1] != -1)
                low = dp[n - 1][f - 1];
            else
            {
                low = solve(n - 1, f - 1);
                dp[n - 1][f - 1] = low;
            }

            if (dp[n][k - f] != -1)
                high = dp[n][k - f];
            else
            {
                high = solve(n, k - f);
                dp[n][k - f] = high;
            }

            int temp = 1 + max(low, high);

            mn = min(mn, temp);
        }

        return dp[n][k] = mn;
    }

    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n, k);
    }
};

int main()
{

    // taking eggs and floors count
    int n, k;
    cout << "Enter Number of Eggs and Floors : " << endl;
    cin >> n >> k;
    Solution ob;
    // calling function eggDrop()
    cout << "The minimum number of attempts we need in order to find the critical floor is " << ob.eggDrop(n, k) << endl;

    return 0;
}