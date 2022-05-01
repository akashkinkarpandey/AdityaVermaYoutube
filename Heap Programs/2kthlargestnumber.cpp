#include<iostream>
#include<queue>
using namespace std;
int main()
{
int size,k;
cin>>size>>k;
int a[size];
for(int i=0;i<size;i++)
    cin>>a[i];
priority_queue<int,vector<int>,greater<int>>mini;
for(int i=0;i<size;i++)
{
    mini.push(a[i]);
    if(mini.size()>k)
    mini.pop();
}
cout<<mini.top()<<endl;
return 0;
}