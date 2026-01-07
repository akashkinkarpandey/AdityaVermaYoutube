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
priority_queue<int>mini;//max heap
for(int i=0;i<size;i++)
{
    mini.push(a[i]);
    if(mini.size()>k)
    mini.pop();
}
while(!mini.empty())
{
    cout<<mini.top()<<endl;
    mini.pop();
}
return 0;
}
