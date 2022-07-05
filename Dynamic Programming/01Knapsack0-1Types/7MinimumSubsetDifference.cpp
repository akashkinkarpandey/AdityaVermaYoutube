#include <iostream>
#include <vector>
using namespace std;
//video 10 of aditya verma
// Enter size
// 4
// Enter array elements
// 1 6 11 5
// Minimum subset sum is 1

// sum of {1,6,5} - sum of {11} = 1

//find range -2*S1 instead of S2-S1
//find S1 in 1 to range/2 
bool subset(int n, int target, int a[], vector<vector<bool>> &dp)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j] ||
                            dp[i - 1][j - a[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}
int main()
{
    printf("Enter size\n");
    int n;
    scanf("%d", &n);
    int a[n];
    int sum = 0;
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int target = sum;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1));
    // if n=0,no target sum can be reached ,
    // hence 1st row should be zero
    for (int i = 0; i <= target; i++)
        dp[0][i] = false;
    // if target is zero,any given array will have the empty subset
    // so entire 0th column is true by over-writing dp[0][0]
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    subset(n, target, a, dp);
    for (int i = target / 2; i >= 1; i--)
    {
        if (dp[n][i] == true)
        {
            cout << "Minimum subset sum is " << sum - (2 * i) << endl;
            break;
        }
    }
    return 0;
}