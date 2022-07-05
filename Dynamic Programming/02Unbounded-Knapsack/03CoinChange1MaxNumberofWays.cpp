#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//this is coin change 2 on leetcode
//infinite supply of coins
//that is pick a coin any number of times
// https://leetcode.com/problems/coin-change-2/
//this is coin change 2 on leetcode

// Enter size
// 3
// Enter coin denominations
// 1 2 3
// Enter amount_required
// 5
// Maximum ways to sum upto amount is 5


// Enter size
// 3
// Enter coin denominations
// 1 2 5
// Enter amount_required
// 5
// Maximum ways to sum upto amount is 4
int CoinChange1(int coin[], int n, int amount_required, vector<vector<int>> &dp)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount_required; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j]+dp[i][j - coin[i - 1]];
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
    vector<vector<int>> dp(n + 1, vector<int>(amount_required + 1));
    for (int i = 0; i <=amount_required ; i++)
        dp[0][i] = 0;
    for (int i = 0; i <=n; i++)
        dp[i][0] = 1;
    printf("Maximum ways to sum upto amount is %d\n", CoinChange1(coin, n, amount_required, dp));
    return 0;
}