#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// check if X is a subsequence of Y
// or if Y is a subsequence of X
// Enter string 1 and string 2
// abc
// abcd
// abc is a subsequence of abcd

// Enter string 1 and string 2
// abef
// af
// af is a subsequence of abef
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
    if (LCS(X, Y, n, m, dp) == n)
    {
        cout << X << " is a subsequence of " << Y << endl;
    }
    else if (LCS(X, Y, n, m, dp) == m)
    {
        cout << Y << " is a subsequence of " << X << endl;
    }
    else
    {
        cout<<"Neither is a subsuquence of each other\n";
    }
    return 0;
}