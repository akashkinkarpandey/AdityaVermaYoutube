#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//number of insertion equal to number of deletion
// Enter string
// agbcba
// Minimum Insertion to make palindromic string is
// 1

//explanation->insert g on right hand side
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
int main()
{
    string X;
    cout << "Enter string \n";
    cin >> X;
    string Y = X;
    reverse(Y.begin(), Y.end());
    // Initialization
    int n = X.size();
    int m = Y.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    //number of insertion is equal to number of deletions
    cout << "Minimum Insertion to make palindromic string is\n";
    cout << n-LCS(X, Y, n, m, dp) << endl;
    return 0;
}