#include "bits/stdc++.h"
#include <vector>
#include <string>

using namespace std;

int longestKSubstr(string s, int k) 
{
    int i=0;
    int j=0;
    int ans = 0;
    int size = s.size();
    unordered_map<char,int> map;
        
    while(j < size)
    {
        map[s[j]]++;
        if(map.size() < k)
            j++;
            
        else if(map.size() == k)
        {
            ans = max(ans,j-i+1);
            j++;
        }
        else if(map.size() > k)
        {
            while(map.size()>k)
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
	string s = "aabacbebebe";
	int ans;
	ans = longestKSubstr(s,3);
	cout << ans;
	return 0;
}
