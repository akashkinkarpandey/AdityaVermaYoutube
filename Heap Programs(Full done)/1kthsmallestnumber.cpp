#include<iostream>
#include<queue>
using namespace std;
int main()
{
int size,k;
cin>>size>>k;
int a[size];
for(int i=0;i<size;i++)
{
    cin>>a[i];
}
priority_queue<int>maxi;
for(int i=0;i<size;i++)
{
    maxi.push(a[i]);
    if(maxi.size()>k)
    maxi.pop();
}
cout<<maxi.top()<<endl;
return 0;
}