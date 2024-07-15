#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(vector<int> &nums, int target)
{

    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if(mid-1>=0)
        {
            if(nums[mid-1] == target)
            return mid-1;
        }
        if(mid+1<=nums.size()-1)
        {
            if(nums[mid+1] == target)
            return mid+1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 2;
        }
        else if (nums[mid] > target)
        {
            high = mid - 2;
        }
    }
    return -1;
}
int main()
{
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
    int t=BinarySearch(v,target);
    cout<<t;
}
//5 10 20 30 40
//element at index i may be at index i-1 or index i+1 or index i
