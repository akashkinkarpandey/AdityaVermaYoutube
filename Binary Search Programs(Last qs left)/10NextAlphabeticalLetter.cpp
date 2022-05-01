#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(vector<char> &nums, char target)
{
    int res = nums.size();
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            low=mid+1;
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
    int n;char target;
    vector<char> v;
    cin >> n;
    cin >> target;
    for (int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        v.push_back(x);
    }
    int t = BinarySearch(v, target);
    cout<<t<<endl;
    return 0;
}
//if element is d,next greater is f(answer is 2(index))
// a c f h