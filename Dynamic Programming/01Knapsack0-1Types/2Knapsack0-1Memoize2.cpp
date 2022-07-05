#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// This is way 2
// we make dp matrix of w+1 rows and n+1 columns
//  Enter size
//  3
//  Enter weight array
//  10 20 30
//  Enter value array
//  60 100 120
//  Enter capacity
//  50
//  MAX profit is 220
int knapSack01(int wt[], int val[], int n, int capacity, vector<vector<int>> &dp)
{
    if (n == 0 or capacity == 0)
        return 0;
    if (dp[capacity][n] != -1)
        return dp[capacity][n];
    if (wt[n - 1] <= capacity)
    {
        return dp[capacity][n] = max(
                   val[n - 1] + knapSack01(wt, val, n - 1, capacity - wt[n - 1], dp),
                   knapSack01(wt, val, n - 1, capacity, dp));
    }
    else if (wt[n - 1] > capacity)
    {
        return dp[capacity][n] = knapSack01(wt, val, n - 1, capacity, dp);
    }
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
    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= capacity; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;
    printf("MAX profit is %d\n", knapSack01(wt, val, n, capacity, dp));
    return 0;
}