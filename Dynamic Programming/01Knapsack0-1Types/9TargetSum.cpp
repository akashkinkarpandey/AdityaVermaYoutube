#include <iostream>
#include <vector>
using namespace std;
//video 12 of aditya verma

//put + or - infront of array elements so that they ultimately make upto to target sum

// Enter size
// 4
// Enter array elements
// 1 1 2 3
// Enter difference
// 1
// Number of pairs of subsets is 3

// Explanation-
// {1,3} and {1,2}
// {1,3} and {1,2}
// {1,1,2} and {1,3} ->3 pairs of subsets
int subset(int n,int target,int a[],vector<vector<int>>&dp)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=target;j++)
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
    int n,sum=0;
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    printf("Enter target ans\n");
    int target_ans;
    scanf("%d",&target_ans);
    int target=(sum+target_ans)/2;
    vector<vector<int>>dp(n+1,vector<int>(target+1));
    //if n=0,no target sum can be reached,
    //hence 1st row should be zero
    for(int i=0;i<=target;i++)
    dp[0][i]=0;
    //if target is zero,any given array will have the empty subset
    //so entire 0th column is true by over-writing dp[0][0]
    for(int i=0;i<=n;i++)
    dp[i][0]=1;
    cout<<"Number of pairs of subsets is "<<subset(n,target,a,dp)<<endl;
    return 0;
}