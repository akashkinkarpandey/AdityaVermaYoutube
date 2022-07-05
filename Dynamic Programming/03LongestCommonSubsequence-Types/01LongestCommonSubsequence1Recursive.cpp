#include <iostream>
#include <algorithm>
using namespace std;
// Enter string 1 and string 2
// aabcd
// aacbd
// Length of Longest Common Subsequence is
// 4

// explanantion-aacd is common subsequnce string
int LCS(string &X, string &Y, int n, int m)
{
    if(m==0 or n==0)
    return 0;
    if(X[n-1]==Y[m-1])
    {
        return 1+LCS(X,Y,n-1,m-1);
    }
    else
    {
        return max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1));
    }
}
int main()
{
    string X;
    string Y;
    cout << "Enter string 1 and string 2\n";
    cin >> X >> Y;
    cout << "Length of Longest Common Subsequence is\n";
    cout << LCS(X, Y, X.size(), Y.size()) << endl;
    return 0;
}