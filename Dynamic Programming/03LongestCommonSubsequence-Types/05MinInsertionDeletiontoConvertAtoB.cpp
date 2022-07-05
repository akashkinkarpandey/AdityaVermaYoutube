#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Leetcode Link Accepted
// https://leetcode.com/problems/delete-operation-for-two-strings/

// Enter string 1 and string 2
// heap
// pea
// Minimum Insertions,deletion to convert a to b is
// 3

//delete h and p->ea remains(2 deletions)
//insert p to make ea to pea(1 insertion)
int LCS(string &X, string &Y, int n, int m,vector<vector<int>>&dp)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(X[i-1]==Y[j-1])
            {
            dp[i][j]=1+dp[i-1][j-1];
            }   
            else
            {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }         
        }
    }
    return dp[n][m];
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
    cout << "Minimum Insertions,deletion to convert a to b is\n";
    cout << (m-LCS(X, Y, n, m,dp)+n-LCS(X, Y, n, m,dp)) << endl;
    return 0;
}