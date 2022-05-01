#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
int i=0;
while(i<n)
{
    if(a[i]!=a[a[i]-1])
    {
        int t=a[i];
        a[i]=a[a[i]-1];
        a[a[i]-1]=t;
    }
    else i++;
}
i=0;
while(i<n)
{
    if(a[i]!=i+1)
    {
    cout<<a[i]<<" is Duplicate"<<endl;
    cout<<i+1<<" not found"<<endl;
    }
i++;
}
return 0;
}