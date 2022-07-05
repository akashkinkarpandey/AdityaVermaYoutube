#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Enter string 1 and string 2
// aabc
// aaec
// Length of Longest Common Substring is
// 2

// Enter string 1 and string 2
// abcde
// bcdgggg
// Length of Longest Common Substring is
// 3
//explanation-bcd is common substring
int LCSubstring(string &X, string &Y, int n, int m,vector<vector<int>>&dp)
{
    int maxi=0;
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
            dp[i][j]=0;
            }      
            maxi=max(maxi,dp[i][j]);   
        }
    }
    return maxi;
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
    cout << "Length of Longest Common Substring is\n";
    cout << LCSubstring(X, Y, n, m,dp) << endl;
    return 0;
}