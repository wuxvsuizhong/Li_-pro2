/*
 一个能抓装M公斤的背包，现有n件物品，它们的重量分别是：W1,W2,W3...Wn，它们的价值分别是C1,C2,C3...Cn,求该背包能够装下最大多大价值的物品。
 输入：
10 4
2 1
3 3
4 5
7 9 
*/


#include<iostream>
using namespace std;

int dp[35][205];
int w[35],c[35];
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>c[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j<w[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[n][m] << endl;
    return 0;
}