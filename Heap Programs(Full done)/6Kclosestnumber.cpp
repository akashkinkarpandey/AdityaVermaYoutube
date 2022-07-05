#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
int main()
{
//input
//5 3 7
//5 6 7 8 9 
//output
//8 6 7
int size,k,target;
cin>>size>>k>>target;
int a[size];
for(int i=0;i<size;i++)
{
    cin>>a[i];
}
priority_queue<pair<int,int>>maxi;
for(int i=0;i<size;i++)
{
    maxi.push({a[i]-target>=0?a[i]-target:target-a[i],a[i]});
    if(maxi.size()>k)
    maxi.pop();
}
while(!maxi.empty())
{
    cout<<maxi.top().second<<endl;
    maxi.pop();
}
return 0;
}