#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//video 6 of aditya verma
// Enter size
// 3
// Enter weight array
// 10 20 30
// Enter value array
// 60 100 120
// Enter capacity
// 50
// MAX profit is 220
int knapSack01(int wt[], int val[], int n, int capacity, vector<vector<int>> &dp)
{
    //n changes to i
    //capacity changes to j
    //return dp[n][capacity] changes to dp[i][j]
    //function calls change to dp[i][j]
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=capacity;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else if(wt[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][capacity];
}
int main()
{
    printf("Enter size\n");
    int n;
    scanf("%d", &n);
    int wt[n], val[n];
    printf("Enter weight array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &wt[i]);
    }
    printf("Enter value array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }
    printf("Enter capacity\n");
    int capacity;
    scanf("%d", &capacity);
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= capacity; i++)
        dp[0][i] = 0;
    printf("MAX profit is %d\n", knapSack01(wt, val, n, capacity, dp));
    return 0;
}