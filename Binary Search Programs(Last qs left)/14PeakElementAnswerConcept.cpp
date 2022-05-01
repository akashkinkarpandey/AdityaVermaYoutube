#include <iostream>
#include <vector>
using namespace std;
//fuction is inc,dec,inc,dec
//so multiple peaks,
//hence return type is vector

// https://leetcode.com/problems/find-peak-element/
int BinarySearch(vector<int> &a)
{   //this function is in leetcode and got accepted
    int t = a.size();
    // vector<int> v;
    int low = 0, high = t - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid > 0 and mid < t - 1)
        {
            if (a[mid] > a[mid - 1] and a[mid] > a[mid + 1])
               return mid;
            else if (a[mid - 1] > a[mid])
            {
                high = mid - 1;
            }
            else if (a[mid + 1] > a[mid])
            {
                low = mid + 1;
            }
        }
        else if (mid == 0)
        {
            if (a[0] > a[1])
                   return 0;
                   low=mid+1;
        }
        else if (mid == t - 1)
        {
            if (a[t - 1] > a[t - 2])
                   return t-1;
                    high=mid-1;   
        }
    }

    return -1;
}
vector<int> BinarySearch1(vector<int> &a)
{   //this function is not in leetcode
    int t = a.size();
    vector<int> v;
    int low = 0, high = t - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid > 0 and mid < t - 1)
        {
            if (a[mid] > a[mid - 1] and a[mid] > a[mid + 1])
                v.push_back(mid);
            else if (a[mid - 1] > a[mid])
            {
                //whichever is greater in that diection
                high = mid - 1;
            }
            else if (a[mid + 1] > a[mid])
            {
                low = mid + 1;
            }
        }
        else if (mid == 0)
        {
            if (a[0] > a[1])
                v.push_back(0);
            low = mid + 1;
        }
        else if (mid == t - 1)
        {
            if (a[t - 1] > a[t - 2])
                v.push_back(t - 1);
            high = mid - 1;
        }
    }
    return v;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    if (v.size() == 1)
    {
        cout << 0;
        return 0;
    }
    //indexes of peak elements are printed
    vector<int> d = BinarySearch(v);
    for (auto &i : d)
        cout << i << endl;
}

//10 20 15 2 23 90 67
//answer might be 20 or 90

// first and element should be greater than aadjacent element to be a peak element