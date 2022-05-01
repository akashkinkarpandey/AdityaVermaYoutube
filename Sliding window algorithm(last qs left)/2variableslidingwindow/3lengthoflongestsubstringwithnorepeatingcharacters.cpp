#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int i = 0, j = 0, maxi = INT_MIN;
    unordered_map<char, int> m;
    while (j < s.length())
    {
        m[s[j]]++;
        if (m.size() == j - i + 1)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else if (m.size() < j - i + 1)
        {
            while (m.size() < j - i + 1)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    cout<<maxi<<endl;
}