#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Enter string 1 and string 2
// agbhc
// aibec
// Length of Longest Common Subsequence is
// 3

// DP TABLE IS
// 0 0 0 0 0 0
// 0 1 1 1 1 1
// 0 1 1 1 1 1
// 0 1 1 2 2 2
// 0 1 1 2 2 2
// 0 1 1 2 2 3
// Dry run is
// 5 5 c
// 4 4 e
// 4 3 h
// 3 3 b
// 2 2 i
// 2 1 g
// 1 1 a

// Shortest Common Supersequence is agibhec
int LCS(string &X, string &Y, int n, int m, vector<vector<int>> &dp)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
string generate(string &X, string &Y, int n, int m, vector<vector<int>> &dp)
{
    string s = "";
    int i = n;
    int j = m;
    while (i > 0 and j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            cout<<i<<" "<<j<<" "<<Y[j - 1]<<endl;
            s.push_back(Y[j - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                cout<<i<<" "<<j<<" "<<X[i-1]<<endl;
                s.push_back(X[i - 1]);
                i--;
            }
            else
            {
                cout<<i<<" "<<j<<" "<<Y[j-1]<<endl;
                s.push_back(Y[j - 1]);
                j--;
            }
        }
    }
    while (i > 0)
    {
        s += X[i - 1];
        i--;
    }
    while (j > 0)
    {
        s += X[j - 1];
        j--;
    }
    cout<<"\n";
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    string X;
    string Y;
    cout << "Enter string 1 and string 2\n";
    cin >> X >> Y;
    // Initialization
    int n = X.size();
    int m = Y.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    cout << "Length of Longest Common Subsequence is\n";
    cout << LCS(X, Y, n, m, dp) << endl;
    cout<<"\n";
    cout<<"DP TABLE IS\n";
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    cout<<"Dry run is\n";
    string s=generate(X, Y, n, m,dp) ;
    cout << "Shortest Common Supersequence is "<<s<<endl;
    cout<<"\n";
    return 0;
}