#include<iostream>
#include<climits>
#include <cstring>
using namespace std;
// Enter number of dimensions
// 5
// Enter the dimensions
// 3 2 4 2 5
// Number of operations is 58
int dp[1001][1001];
int solve(int arr[],int i,int j)
{
    if(i>=j)
        return dp[i][j]=0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int mini=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp_ans=solve(arr,i,k)+solve(arr,k+1,j);
        temp_ans+=arr[i-1]*arr[j]*arr[k];
        if(temp_ans<mini)
            mini=temp_ans;
    }
    return dp[i][j]=mini;
}
int main()
{
    int n;
    printf("Enter number of dimensions\n");
    scanf("%d",&n);
    int a[n];
    memset(dp,-1,sizeof(dp));
    printf("Enter the dimensions\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    cout<<"Number of operations is "<<solve(a,1,n-1)<<endl;
}