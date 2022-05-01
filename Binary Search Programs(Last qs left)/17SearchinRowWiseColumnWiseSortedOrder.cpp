#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int n=50;
const int m=50;
pair<int,int> func(int a[][m],int b,int target)
{
    int i=0,j=b-1;
    while(i>=0 && i<n && j>=0 && j<b)
    {
        if(a[i][j]==target)
        return {i,j};
        else if(a[i][j]>target)
        j--;
        else if(a[i][j]<target)
        i++;
    }
    return {-1,-1};
}
int main()
{
    int target;int b;
    cin>>n>>b>>target;
     int a[n][m];
    for (int i=0;i<n;i++)
        for(int j=0;j<b;j++)
              cin>>a[i][j];
    pair<int,int>t= func(a,target,b);
    cout<<t.first<<" "<<t.second<<endl;
}