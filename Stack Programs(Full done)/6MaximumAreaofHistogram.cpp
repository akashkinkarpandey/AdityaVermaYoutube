#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<utility>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    //task1
    //next smaller element to right index
    stack<pair<int,int>>s,s1;
    vector<int>v,v1;
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
        v.push_back(n);
        else if(s.size()>0 &&s.top().first<a[i])
        v.push_back(s.top().second);
        else if(s.size()>0 && s.top().first>=a[i])
        {
            while(s.size()>0 &&s.top().first>=a[i])
            {
                s.pop();
            }
            if(s.size()==0)
            v.push_back(n);
            else v.push_back(s.top().second);
        }
        s.push({a[i],i});
    }
    reverse(v.begin(),v.end());
    
    //task2
    //next smaller element to left's index

    for(int i=0;i<=n-1;i++)
    {
        if(s1.size()==0)
        v1.push_back(-1);
        else if(s1.size()>0 &&s1.top().first<a[i])
        v1.push_back(s1.top().second);
        else if(s1.size()>0 && s1.top().first>=a[i])
        {
            while(s1.size()>0 &&s1.top().first>=a[i])
            {
                s1.pop();
            }
            if(s1.size()==0)
            v1.push_back(-1);
            else v1.push_back(s1.top().second);
        }
        s1.push({a[i],i});
    }
    //task 3
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int x=v[i]-v1[i]-1;//calculating wdth
        int y=x*a[i];//calculating area
        maxi=max(maxi,y);//calculating max area
    }
    cout<<maxi<<endl;


}