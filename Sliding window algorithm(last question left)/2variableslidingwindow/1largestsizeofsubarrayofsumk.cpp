#include <iostream>
#include <limits.h>
using namespace std;
//does not work for negative numbers
int main()
{
    int i = 0, j = 0, c = 0, d = 0, sum = 0, maxi = INT_MIN;
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (j < n)
    {
        sum += a[j];
        if (sum < k)
            j++;
        else if (sum == k)
        {
            maxi = max(maxi, j - i + 1);
            if (maxi == j - i + 1)
            {
                c = i;
                d = j;
            }
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum -= a[i];
                i++;
                if (sum == k)
                {
                    maxi = max(maxi, j - i + 1);
                    if (maxi == j - i + 1)
                    {
                        c = i;
                        d = j;
                    }
                    break;
                }
            }
            j++;
        }
    }
    cout << maxi << " " << c + 1 << " " << d + 1 << endl;
    return 0;
}