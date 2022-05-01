#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    unordered_map<char, int> mp;
    //storing frequency
    string s, s1;
    cin >> s >> s1;
    //s is big string
    //s1 is string whose anagram needs to be found
    vector<int> v;
    //storing starting index of correct anagram
    int n = s.length();
    int m = s1.length();
    for (auto i : s1)
        mp[i]++;
    int answer = 0;//counts total number of anagrams
    int count = mp.size();
    //count stores number of unique elements
    int i = 0, j = 0;
    while (j < n)
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;
        }
        if ((j - i + 1) < m)
            j++;
        else if ((j - i + 1) == m)
        {
            if (count == 0)
            {
                v.push_back(i);
                answer++;
            }
            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]++;
                if (mp[s[i]] == 1)
                    count++;
            }
            i++;
            j++;
        }
    }
    cout << answer << endl;
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}
