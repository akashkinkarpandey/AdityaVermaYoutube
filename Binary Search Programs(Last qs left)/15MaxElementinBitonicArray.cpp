#include <iostream>
#include <vector>
using namespace std;
//Bitonic() is increasing then decreasing
// https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/
//leetcode accepted
// https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1#

int BinarySearch(vector<int> &a)
{
    int t = a.size();
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
            return (a[0] > a[1]) ? 0 : 1;
        }
        else if (mid == t - 1)
        {
            if (a[t - 1] > a[t - 2])
                return t - 1;
            return t - 2;
        }
    }

    return -1;
}
int main()
{
    //input is 1 3 8 12 4 2
    //ouptut 12

    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int t = BinarySearch(v);
    cout << t << endl; //index returned
}
//5 4 3 2 1 
//answer is 0(index of 5) as peak is 5(decreasing from 5(peak))

//1 2 3 4 5
//answer is 4(index of 5)


//there will be just one max(peek) element in array
//no multiple peeks