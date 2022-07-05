#include <iostream>
#include <algorithm>
using namespace std;
// Enter size
// 3
// Enter weight array
// 10 20 30
// Enter value array
// 60 100 120
// Enter capacity
// 50
// MAX profit is 220
int knapSack01(int wt[], int val[], int n, int capacity)
{
    if (n == 0 or capacity == 0)
        return 0;
    if (wt[n - 1] <= capacity)
    {
        return max(
            val[n - 1] + knapSack01(wt, val, n - 1, capacity - wt[n - 1]),
            knapSack01(wt, val, n - 1, capacity));
    }
    else if (wt[n - 1] > capacity)
    {
        return knapSack01(wt, val, n - 1, capacity);
    }
}
int main()
{
    printf("Enter size\n");
    int n;
    scanf("%d", &n);
    int wt[n], val[n];
    printf("Enter weight array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &wt[i]);
    }
    printf("Enter value array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }
    printf("Enter capacity\n");
    int capacity;
    scanf("%d", &capacity);
    printf("MAX profit is %d\n", knapSack01(wt, val, n, capacity));
    return 0;
}