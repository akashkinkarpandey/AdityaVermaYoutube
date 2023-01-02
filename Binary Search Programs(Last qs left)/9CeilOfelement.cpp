#include <iostream>
#include <vector>
using namespace std;
//if number is present return it
//if not present find smallest number greater than it
int BinarySearch(vector<int> &nums, int target)
{
    int res = -1;
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            
        low = mid + 1;
        }
        else if (nums[mid] > target)
        {
            res=mid;
            high = mid - 1;

        }
    }
        return res;
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
    int t = BinarySearch(v, target);
    cout<<t<<endl;
    return 0;
}
