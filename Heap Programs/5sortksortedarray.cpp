#include<iostream>
#include<queue>
using namespace std;
int main()
{
vector<int>v;
int size,k;
cin>>size>>k;
int a[size];
for(int i=0;i<size;i++)
cin>>a[i];
priority_queue<int,vector<int>,greater<int>>mini;//min heap
for(int i=0;i<size;i++)
{
    mini.push(a[i]);
    if(mini.size()>k)
    {
        v.push_back(mini.top());
        mini.pop();
    }
}
while(!mini.empty())
{
    v.push_back(mini.top());
    mini.pop();
}
for(auto i:v)
cout<<i<<" ";
return 0;
}