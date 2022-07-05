#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Enter string 1 and string 2
// aabd
// ad
// Length of Longest Common Subsequence is
// 2

//explanantion->ad is part of both strings as subsequence
int LCS(string &X, string &Y, int n, int m,vector<vector<int>>&dp)
{
    if(m==0 or n==0)
    return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(X[n-1]==Y[m-1])
    {
       return dp[n][m]=1+LCS(X,Y,n-1,m-1,dp);
    }
    else
    {
        return dp[n][m]=max(LCS(X,Y,n-1,m,dp),LCS(X,Y,n,m-1,dp));
    }
}
int main()
{
    string X;
    string Y;
    cout << "Enter string 1 and string 2\n";
    cin >> X >> Y;
    //Initialization
    int n=X.size();
    int m=Y.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=m;i++)
    dp[0][i]=0;
    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    cout << "Length of Longest Common Subsequence is\n";
    cout << LCS(X, Y, n, m,dp) << endl;
    return 0;
}