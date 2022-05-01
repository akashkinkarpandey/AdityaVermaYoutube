#include <iostream>
#include <vector>
using namespace std;
int count(vector<int> &nums)
{
    int len=nums.size();
    int low = 0, high = len - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int next=(mid+1)%(len);
        int prev=(mid+len-1)%(len);
        if (nums[mid] <=nums[next] && nums[mid]<=nums[prev])
        {
            return mid;
        }
        else if (nums[mid] <= nums[high])
        {
        high = mid-1;
        }
        else if (nums[low]<=nums[mid])
        {
        low = mid+1;
        }
    }
   
    return -1;
}
int main()
{
 int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int t = count(v);
    cout<<t<<endl;
    return 0;
}


//2 5 6 8 11 12 15 18
//11 12 15 18 2 5 6 8
//(array is sorted rotated)

//2 3 4 5 1
//index of smallest element is answer ,answer is 4(index of 1)

//search in unsorted part
//there lies minimum element