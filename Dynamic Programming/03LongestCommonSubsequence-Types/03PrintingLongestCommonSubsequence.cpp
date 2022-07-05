//  left to be done
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Enter string 1 and string 2
// abcff
// acffb
// Length of Longest Common Subsequence is
// 4
// Longest Common Subsequence is
// acff
vector<string>ans;
string temp;
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
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }      
            maxi=max(maxi,dp[i][j]);   
        }
    }
    return maxi;
}
string generate(string &X, string &Y,int n,int m,vector<vector<int>>&dp)
{
    string s="";
    int i=n;
    int j=m;
    while(i>0 and j>0)
    {
        if(X[i-1]==Y[j-1])
        {
            s.push_back(X[i-1]);
            i--;j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else j--;
        }
    }
    reverse(s.begin(),s.end());
    return s;
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
    cout << LCSubstring(X, Y, n, m,dp) << endl;
     cout << "Longest Common Subsequence is\n";
    cout << generate(X, Y, n, m,dp) << endl;
    return 0;
}