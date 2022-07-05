#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Enter size of rod
// 8
// Enter profit array
// 1 5 8 9 10 17 17 20
// MAX profit is 22
//expnanation-by cutting into 2 pieces of length 2 and 6

// Enter size of rod
// 8
// Enter profit array
// 3 5 8 9 10 17 17 20
// MAX profit is 24
// by cutting into 8 pieces of length 1
int RodCutting(int length[], int val[], int n, int len, vector<vector<int>> &dp)
{
    //n changes to i
    //len changes to j
    //return dp[n][len] changes to dp[i][j]
    //function calls change to dp[i][j]
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=len;j++)
        {
            if(length[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }
            else if(length[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][len];
}
int main()
{
    printf("Enter size of rod\n");
    int n;
    scanf("%d", &n);
    int length[n], val[n];
    for (int i = 0; i < n; i++)
    {
        length[i]=i+1;
    }
    printf("Enter profit array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    //profit is zero when array size is zero
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    //profit is zero when length of rod is zero
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;
    printf("MAX profit is %d\n", RodCutting(length, val, n, n, dp));
    return 0;
}