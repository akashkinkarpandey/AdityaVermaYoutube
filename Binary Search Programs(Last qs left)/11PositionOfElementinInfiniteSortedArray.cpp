#include <iostream>
#include <vector>
using namespace std;
//search in array with huge number of elements
//hence take low and high within and appropriate range
//then search to reduce search space

int BinarySearch(vector<int> &nums, int target, int low, int high)
{
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            res = mid;
            break;
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
    return res;
}
int main()
{
    int n, target;
    vector<int> v;
    cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int low = 0, high = 1;
    while (v[high]<target )
    {
        low = high;
        high = high * 2;
    }
    int t = BinarySearch(v, target, low, high);
    cout << t << endl;
}
