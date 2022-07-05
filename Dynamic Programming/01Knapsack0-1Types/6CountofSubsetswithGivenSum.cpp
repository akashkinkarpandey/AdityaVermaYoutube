#include <iostream>
#include <vector>
using namespace std;
//video 9 of aditya verma
// Enter size
// 6
// Enter array elements
// 2 3 5 6 8 10
// Enter target sum
// 10
// Number of subsets is 3

//explanation
// {2,8}
// {10},
// {5,2,3} are the 3 subsets
int subset(int n,int target,int a[],vector<vector<int>>&dp)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            if(a[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
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
    vector<vector<int>>dp(n+1,vector<int>(target+1));
    //if n=0,no target sum can be reached ,
    //hence 1st row should be zero
    for(int i=0;i<=target;i++)
    dp[0][i]=0;
    //if target is zero,any given array will have the empty subset
    //so entire 0th column is true by over-writing dp[0][0]
    for(int i=0;i<=n;i++)
    dp[i][0]=1;
    cout<<"Number of subsets is "<<subset(n,target,a,dp)<<endl;
    return 0;
}