#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int main()
{
//min heap of pairs
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mini;
unordered_map<int,int>mp;
int size,k;
cin>>size>>k;
int a[size];
for(int i=0;i<size;i++)
{
    cin>>a[i];
    mp[a[i]]++;
}
for(auto i:mp)
{
mini.push({i.second,i.first});
if(mini.size()>k)
mini.pop();
}
while(mini.size()>0)
{
    cout<<mini.top().second<<endl;
    mini.pop();
}
}