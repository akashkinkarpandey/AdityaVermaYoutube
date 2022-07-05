#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;
int main()
{
    vector<int>v;
    stack<int>s;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<=n-1;i++)
    {
        if(s.size()==0)
        v.push_back(-1);
        else if(s.size()>0 &&s.top()<a[i])
        v.push_back(s.top());
        else if(s.size()>0 && s.top()>=a[i])
        {
            while(s.size()>0 &&s.top()>=a[i])
            {
                s.pop();
            }
            if(s.size()==0)
            v.push_back(-1);
            else v.push_back(s.top());
        }
        s.push(a[i]);
    }
    for(auto i:v)
    cout<<i<<" ";
    cout<<endl;
}