#include <iostream>
#include <vector>
using namespace std;
int firstOccurence(vector<int> &nums, int target)
{
    int res = nums.size();
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            res = mid;
            high = mid - 1;
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
    if (nums[res] == target)
        return res;
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
    int t = firstOccurence(v, target);
    cout<<t;
    return 0;
}
