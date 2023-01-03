#include <iostream>
#include <vector>
#include <utility>
using namespace std;
//columns are sorted in increasing order
//rows are sorted in increasing order
//10 20 30 40
//15 25 35 45
//27 29 37 48
//32 33 39 50
//search for 29 (start from top right corner)
//type of qs->https://leetcode.com/problems/search-a-2d-matrix/ 
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
        j--;//reduce column
        else if(a[i][j]<target)
        i++;//increase row
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
