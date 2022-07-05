#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;
int main()
{
    priority_queue<pair<int,pair<int, int>>> maxi;
    unordered_map<int,int>mp;
    int size,k;
    cin>>size>>k;
    int a[size][2];
    for(int i=0;i<size;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    for(int i=0;i<size;i++)
    {
    maxi.push({a[i][0]*a[i][0]+a[i][1]*a[i][1],{a[i][0],a[i][1]}});
    if(maxi.size()>k)
    maxi.pop();
    }
    cout<<"---------"<<endl;
    while(maxi.size()>0)
    {
        pair<int,int>p=maxi.top().second;
        cout<<p.first<<" "<<p.second<<endl;
        maxi.pop();
    }
}


