#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    list<int> l;
    vector<int> v;
    int i = 0, j = 0;
    while (j < n)
    {
        if (l.size() > 0 && l.back() < a[j])
        l.pop_back();
        l.push_back(a[j]);
        if(j-i+1<k)
        j++;
        else if(j-i+1==k)    
        {
            v.push_back(l.front());
            if(a[i]==l.front())
            l.pop_front();
            i++;j++;
        }
    }
for(auto i:v)
cout<<i<<" ";
cout<<endl;
}