#include <iostream>
#include <vector>
using namespace std;
//video 7 of aditya verma

// we just need to return true or false
// based on fact if sum of subset equals to target sum
// subset may or may not contain any elements

// Enter size
// 5
// Enter array elements
// 2 3 7 8 10
// Enter target sum
// 11
// Yes ,subset sum exists

// Explanation-
// 3+8=11
bool subset(int n,int target,int a[],vector<vector<bool>>&dp)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            if(a[i-1]<=j)
            {
                dp[i][j]=(
                    dp[i-1][j] ||
                    dp[i-1][j-a[i-1]]
                );
            }
            else
            {
                dp[i][j]=dp[i-1][j];
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
    printf("Enter array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter target sum\n");
    int target;
    scanf("%d",&target);
    vector<vector<bool>>dp(n+1,vector<bool>(target+1));
    //if n=0,no target sum can be reached ,
    //hence 1st row should be zero
    for(int i=0;i<=target;i++)
    dp[0][i]=false;
    //if target is zero,any given array will have the empty subset
    //so entire 0th column is true by over-writing dp[0][0]
    for(int i=0;i<=n;i++)
    dp[i][0]=true;
    if(subset(n,target,a,dp))
    {
        cout<<"Yes ,subset sum exists\n";
    }
    else cout<<"No,subset sum does not exist\n";
    return 0;
}