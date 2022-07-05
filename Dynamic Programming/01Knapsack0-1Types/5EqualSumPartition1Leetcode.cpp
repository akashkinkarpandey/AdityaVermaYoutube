// https://leetcode.com/problems/partition-equal-subset-sum/
// class Solution {
// public:
// bool subset(int n, int target,vector<int>& a, vector<vector<bool>> &dp)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= target; j++)
//         {
//             if (a[i - 1] <= j)
//             {
//                 dp[i][j] = (dp[i - 1][j] ||
//                             dp[i - 1][j - a[i - 1]]);
//             }
//             else
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }
//     return dp[n][target];
// }
//     bool canPartition(vector<int>& a) 
//     {
//     int sum = 0;
//     int n=a.size();
//     for (int i = 0; i < n; i++)
//     {
//         sum += a[i];
//     }
//         if ((sum & 1) == 1)
//     {
//         return 0;
//     }
//     int target=sum>>1;//(sum/2)
//     vector<vector<bool>> dp(n + 1, vector<bool>(target + 1));
//     // if n=0,no target sum can be reached ,
//     // hence 1st row should be zero
//     for (int i = 0; i <= target; i++)
//         dp[0][i] = false;
//     // if target is zero,any given array will have the empty subset
//     // so entire 0th column is true by over-writing dp[0][0]
//     for (int i = 0; i <= n; i++)
//         dp[i][0] = true;
//         return subset(n, target, a, dp);
//     }
// };