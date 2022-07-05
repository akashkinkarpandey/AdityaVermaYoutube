#include<iostream>
#include<queue>
using namespace std;
int ksmallest(int a[],int size,int k)
{
priority_queue<int>maxi;
for(int i=0;i<size;i++)
{
    maxi.push(a[i]);
    if(maxi.size()>k)
    maxi.pop();
}
return maxi.top();
}
int main()
{
int size,k,k1;
cin>>size>>k>>k1;
int a[size];
for(int i=0;i<size;i++)
{
    cin>>a[i];
}
int t=ksmallest(a,size,k);
int t1=ksmallest(a,size,k1);
int sum=0;
for(int i=0;i<size;i++)
{
    if(a[i]>=t &&a[i]<=t1)
    sum+=a[i];
}
cout<<sum<<endl;
}