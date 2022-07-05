#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
//this is coin change 1 on leetcode
//infinte supply of coins
//pick a coin any number of times
//among all possible ways,which way required least number of coins?

// Enter size
// 3
// Enter coin denominations
// 1 2 5
// Enter amount_required
// 5
// Minimum number of coins required is 1

// Enter size
// 3
// Enter coin denominations
// 1 2 3
// Enter amount_required
// 5
// Minimum number of coins required is 2
int CoinChange1(int coin[], int n, int amount_required, vector<vector<int>> &dp)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount_required; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] =min( 
                    dp[i - 1][j],
                    1+dp[i][j - coin[i - 1]]
                    );
            }
            else if (coin[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount_required];
}
int main()
{
    printf("Enter size\n");
    int n;
    scanf("%d", &n);
    int coin[n];
    printf("Enter coin denominations\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coin[i]);
    }
    printf("Enter amount_required\n");
    int amount_required;
    scanf("%d", &amount_required);
    //if we take long long dp matrix
    //we can use INT_MAX instead of INT_MAX-1
    //as overflow wont occur in case of long long
    vector<vector<int>> dp(n + 1, vector<int>(amount_required + 1));
    //when size of array is zero
    //infinite coins will be required to reach amount
    for (int i = 0; i <=amount_required ; i++)
        dp[0][i] = INT_MAX-1;
    //when sum is zero,then 0 coins are required
    for (int i = 0; i <=n; i++)
        dp[i][0] = 0;
    for(int j=1;j<=amount_required;j++)
    {
        if(j%coin[0]==0)
        {
            dp[1][j]=j/coin[0];
        }
        else
        {
            dp[1][j]=INT_MAX-1;
        }
    }
    printf("Minimum number of coins required is %d\n", CoinChange1(coin, n, amount_required, dp));
    return 0;
}
//leetcode accepted
// https://leetcode.com/problems/coin-change/submissions/
// class Solution {
// public:
//      int CoinChange1(int n,int amount,vector<int>& coins,vector<vector<long long>>&dp)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=amount;j++)
//             {
//                 if(coins[i-1]<=j)
//                 {
//                     dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
//                 }
//                 else
//                 {
//                     dp[i][j]=dp[i-1][j];
//                 }
//             }
//         }
//         return (dp[n][amount]==INT_MAX)?-1:dp[n][amount];
//     }
//     int coinChange(vector<int>& coins, int amount) 
//     {
//         int n=coins.size();
//         if(n==1)
//         {
//             if(amount%coins[0]==0)
//                 return amount/coins[0];
//             return -1;
//         }
//         vector<vector<long long>>dp(n+1,vector<long long>(amount+1));
//         for(int i=0;i<=amount;i++)
//             dp[0][i]=INT_MAX;
//         for(int i=0;i<=n;i++)
//             dp[i][0]=0;
       
//         return CoinChange1(n,amount,coins,dp);
//     }
// };