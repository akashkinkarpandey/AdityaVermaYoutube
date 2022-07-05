#include <iostream>
#include <vector>
using namespace std;
//video 8 of aditya verma
// Enter size
// 4
// Enter array elements
// 1 5 11 5
// Yes ,partition can be done
//partition into 2 subsets with equal sums
//explanation:-
//one subset is 1,5,5
//another is 11
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
    if ((sum & 1) == 1)//odd sum 
    {   //division into two subsets not possible
        printf("Not possible\n");
        return 0;
    }
    int target=sum>>1;//(sum/2)
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1));
    // if n=0,no target sum can be reached ,
    // hence 1st row should be zero
    for (int i = 0; i <= target; i++)
        dp[0][i] = false;
    // if target is zero,any given array will have the empty subset
    // so entire 0th column is true by over-writing dp[0][0]
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    if (subset(n, target, a, dp))
    {
        cout << "Yes ,partition can be done\n";
    }
    else
        cout << "No,partition cannot be done\n";
    return 0;
}