#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;
// Enter string
// aab
// Number of partitions are 1
//aa | b
int dp[1001][1001];
bool isPalindrome(string &s,int i,int j)
{
    while(i<=j)
    {
        if(s[i]!=s[j])
            return false;
        i++;j--;
    }
    return true;
}
int solve(string &X,int i,int j)
{
    if(i>=j)
        return dp[i][j]=0;
    if(isPalindrome(X,i,j))
        return dp[i][j]=0;
    int mini=INT_MAX;
    for(int k=i;k<j;k++)
    {
        // int temp=solve(X,i,k)+solve(X,k+1,j)+1;
        int left,right,temp;
        if(dp[i][k]!=-1)
            left=dp[i][k];
            else left=solve(X,i,k);
        // if(temp<mini)
        //     mini=temp;
        if(dp[k+1][j]!=-1)
            right=dp[k+1][j];
            else right=solve(X,k+1,j);
        temp=left+right+1;
        mini=min(mini,temp);
    }
    return dp[i][j]=mini;
}
int main()
{
cout<<"Enter string"<<endl;
string s;
cin>>s;
memset(dp,-1,sizeof(dp));
cout<<"Number of partitions are "<<(solve(s,0,s.size()-1))<<endl;
return 0;
}