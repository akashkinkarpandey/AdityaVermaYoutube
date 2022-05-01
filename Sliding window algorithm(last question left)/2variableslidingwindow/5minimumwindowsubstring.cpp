#include <bits/stdc++.h>
using namespace std;
#define fo(i, m, n) for (long i = m; i < n; i++)
#define ll long long
int main()
{
    string s, s2;
    cin >> s >> s2;
    unordered_map<char, int> mp;
    for(int i=0;i<s2.size();i++)
        mp[s2[i]]++;
    int count = mp.size();
    int mini = INT_MAX;
    string ans;
    for(int i = 0, j = 0;j<s.size();)
    {
        if(mp.find(s[j])!= mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;
        }
        if(count == 0)
        {
            while(count == 0)
            {
                // mini = min(mini, j - i + 1);
                if(j-i+1<mini)
                {
                    mini=j-i+1;
                    ans=s.substr(i,j+1);
                }
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                       { 
                           cout<<i<<" "<<j<<endl;
                           count++;
                       }
                }
                i++;
            }
        }
        j++;
    }
    cout << mini<<" "<<ans<<endl;
    return 0;
}