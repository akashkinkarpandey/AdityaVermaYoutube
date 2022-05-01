#include <iostream>
#include <vector>
using namespace std;
int count(vector<int> &a)
{
    //returns index of min element
    int len=a.size();
    int low = 0, high = len - 1;
    while (low <= high)
    {
        int mid = low+(high-low)/2;
        int next=(mid+1)%(len);
        int prev=(mid+len-1)%(len);
        if (a[mid] <=a[next] && a[mid]<=a[prev])
        {
            return mid;
        }
        else if (a[mid] <= a[high])
        {
        high = mid-1;
        }
        else if (a[mid] >= a[low])
        {
        low = mid+1;
        }
    }
   
    return -1;
}
int BinarySearch(vector<int> &a, int target,int low,int high)
{ //ascending order sorting 
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target)
        {
            low = mid + 1;
        }
        else if (a[mid] > target)
        {
            high = mid - 1;
        }
    }
        return -1;
    
}

int main()
{
    //4 5 1 2 3
    //target is 2
    //output is 3 
    int n,target;
    vector<int> v;
    cin>>n>>target;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int t = count(v);
    // cout<<t;
    //index of min element returned in t
    int find1=BinarySearch(v,target,t,n-1);
    int find2=BinarySearch(v,target,0,t-1);
    if(find1!=-1)
    cout<<find1<<endl;
    else if(find2!=-1)
    cout<<find2<<endl;
    else cout<<"Number not found"<<endl;
    return 0;
}
