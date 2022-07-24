#include <bits/stdc++.h>
using namespace std;

// `````````````I\0````````````````

// Enter the weight of the Knapsack:
// 10
// Enter the number of items:
// 5
// Enter weight and value for the item:
// 3 100
// Enter weight and value for the item:
// 6 30
// Enter weight and value for the item:
// 2 20
// Enter weight and value for the item:
// 7 150
// Enter weight and value for the item:
// 4 110
// Max Profit is 250



int knapSack(int val[],int w[],int W,int n){
    if(n==0||W==0) return 0;

    if(w[n-1]<=W) return max(knapSack(val,w,W-w[n-1],n-1)+val[n-1],knapSack(val,w,W,n-1));
    else if(w[n-1]>W) return knapSack(val,w,W,n-1);
}

int main()
{
    int n,W;
    cout<<"Enter the weight of the Knapsack:"<<endl;
    cin>>W;
    cout<<"Enter the number of items:"<<endl;
    cin>>n;
    int val[n],w[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter weight and value for the item:"<<endl;
        cin>>w[i]>>val[i];
    }

    cout<<"Max Profit is "<<knapSack(val,w,W,n)<<endl;
    
    return 0;
}
