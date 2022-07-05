#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
// Enter string
// aab
// Number of partitions are 1 so tht all strings are plaindrome
//aa | b
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
        return 0;
    if(isPalindrome(X,i,j))
        return 0;
    int mini=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=solve(X,i,k)+solve(X,k+1,j)+1;
        // if(temp<mini)
        //     mini=temp;
        mini=min(mini,temp);
    }
    return mini;
}
int main()
{
cout<<"Enter string"<<endl;
string s;
cin>>s;
cout<<"Number of partitions are "<<(solve(s,0,s.size()-1))<<endl;
return 0;
}