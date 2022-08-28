#include "bits/stdc++.h"
#include <vector>
#include <string>
using namespace std;
int lengthOfLongestSubstring(string s) 
{
    int i=0;
    int j=0;
    int ans=0;
    int size=s.size();
    unordered_map<char,int> map;
        
    while(j<size)
    {
        map[s[j]]++;
        if(map.size() > (j-i+1))
        {
            j++;
        }
        else if(map.size() == j-i+1)
        {
            ans = max(ans,j-i+1);
            j++;
        }
        else if(map.size() < (j-i+1))
        {
            while(map.size() < (j-i+1))
            {
                map[s[i]]--;
                if(map[s[i]]==0)
                {
                    map.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }        
    return ans;
}

int main()
{
	int ans;
	string s = "pwwekew";
	ans = lengthOfLongestSubstring(s);
	cout << ans;
	return 0;
}