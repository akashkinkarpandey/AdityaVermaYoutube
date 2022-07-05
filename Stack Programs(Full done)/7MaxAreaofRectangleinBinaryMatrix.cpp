#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mxl[n];
    int mxr[n];
    mxl[0] = a[0];
    for (int i = 1; i < n; i++)
        mxl[i] = max(mxl[i - 1], a[i]);
    for (int i = 1; i < n; i++)
        mxr[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        mxr[i] = max(mxr[i + 1], a[i]);
    int water[n];
    for (int i = 0; i < n; i++)
        water[i] = min(mxl[i], mxr[i]) - a[i];
    int sum=0;
    for(int i=0;i<n;i++)
    sum=sum+water[i];
    cout<<sum<<endl;
}
