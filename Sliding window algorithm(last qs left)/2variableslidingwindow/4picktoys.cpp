#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;
int main()
{
    //longest substring with k unique characters
    //aabacdebebebe
    //k=3
    //output  7
    //due to cbebebe
    int k;
    k=2;
    string s;
    cin >> s;
    int maxi = INT_MIN;
    unordered_map<char, int> m;
    int i = 0, j = 0;
    while (j < s.length())
    {
        m[s[j]]++;
        if (m.size() < k)
            j++;
        else if (m.size() == k)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else if (m.size() > k)
        {
            //can run a while loop with condition m.size()>k
            m[s[i]]--;
            if (m[s[i]] == 0)
                m.erase(s[i]);
            i++;
            j++;
        }
    }
    cout<<maxi<<endl;
    return 0;
}
