#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(vector<int> &a)
{  
    //Finding Max element in Bitonic Array
    int t=a.size();
    int low = 0, high = t - 1;
    while (low <= high)
    {
       int mid = low+(high - low) / 2;
       if(mid>0 and mid<t-1)
    {
        if(a[mid]>a[mid-1] and a[mid]>a[mid+1])
        return mid;
        else if (a[mid-1] > a[mid])
        {
            high = mid - 1;
        }
        else if (a[mid+1] > a[mid])
        {
            low = mid + 1;
        }
    }
        else if(mid==0)
        {
            return (a[0]>a[1])?0:1;
        }
        else if(mid==t-1)
        {
            if(a[t-1]>a[t-2])
            return t-1;
             return t-2;
        }
    }

    return -1;
}
int BinarySearch(vector<int> &a, int target,int low,int high)
{ 
    //search in ascending order sorting 
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
int revBinarySearch(vector<int> &a, int target,int low,int high)
{//descending order sorting
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target)
        {
            high = mid - 1;
        }
        else if (a[mid] > target)
        {
            low = mid + 1;           
        }
    }
    return -1;
    
}
int main()
{
    //only one peak element
    //1 3 8 12 4 2
    //search in 1 3 8 12(ascending binary search)
    //search in 4 2(descending binary search)
    int n,target;
    vector<int> v;
    cin >> n>>target;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int t=BinarySearch(v);//getting index of max element
    int find1=BinarySearch(v,target,0,t);
    int find2=revBinarySearch(v,target,t+1,n-1);
    if(find1!=-1)
    cout<<find1<<endl;
    else if(find2!=-1)
    cout<<find2<<endl;
    else cout<<"Number not found";
    return 0;
    //Input
    //5 2
    //4 5 1 2 3
    //output
    //3 
}
