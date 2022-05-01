#include<iostream>
#include<limits.h>
#include<vector>
#include<list>
using namespace std;
int main()
{
//-6699 if no negative found
int n,k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
int i=0,j=0;
list<int>l;
vector<int>v;
while(j<n)
{
    if(a[j]<0)
    l.push_back(a[j]);
    if(j-i+1<k)
    j++;
    else if(j-i+1==k)
    {
        if(l.size()==0)
        v.push_back(-6699);
        else
        {
        v.push_back(l.front());
        if(a[i]==l.front())
        l.pop_front();
        }
        i++;j++;
    }
}
for(auto i:v)
cout<<i<<" ";
}