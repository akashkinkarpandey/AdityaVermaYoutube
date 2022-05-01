#include<iostream>
#include<queue>
using namespace std;
int main()
{
int size;
cin>>size;
int a[size];
priority_queue<int,vector<int>,greater<int>>mini;
for(int i=0;i<size;i++)
{
        cin>>a[i];
        mini.push(a[i]);
}
int cost=0;
while(mini.size()>=2)
{
    int f1=mini.top();
    mini.pop();
    int f2=mini.top();
    mini.pop();
    cost+=f1+f2;
    mini.push(f1+f2);
}
cout<<cost<<endl;
return 0;
}