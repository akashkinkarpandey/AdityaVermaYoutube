#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
int main()
{
    priority_queue<pair<int, int>> maxi;
    unordered_map<int,int>mp;
    int size, k;
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
        mp[a[i]]++;

    }
    for(auto i:mp)
    {
        maxi.push({i.second,i.first});
    }
    while(!maxi.empty())
    {
        int freq=maxi.top().first;
        int ele=maxi.top().second;
        for(int i=1;i<=freq;i++)
        cout<<ele<<" ";
        cout<<endl;
        maxi.pop();
    }
}