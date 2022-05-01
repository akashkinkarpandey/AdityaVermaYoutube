#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int BinarySearch(vector<int> &nums, int target)
{
    int res = nums.size();
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            res = mid;break;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
    }
     int t=nums[high]-target;
     int t1=nums[low]-target;
     t=(t<0)?-t:t;
     t1=(t1<0)?-t1:t1;
     return min(t,t1);
     
}
int main()
{
    //input is 2 6 10 15 
    //target is 10
    //answer is 0(10-10)
    int n, target;
    vector<int> v;
    cin >> n;
    cin >> target;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int t = BinarySearch(v, target);
    cout<<t<<endl;
    return 0;
}


//input array is 1 3 8 10 15
//key is 12
//output should be 2 as (abs(12-10) is 2  which is minimum)