#include "bits/stdc++.h"
#include <string>
#include <vector>
using namespace std;

int findAnagrams(string s, string p) 
{        
    int i=0;
    int j=0;        
    int k = p.size();
    int ss = s.size();
    int ans;

    // Store the frequency of the elements in the map
    unordered_map <char, int> mpp;
    for(auto z : p)
        mpp[z]++;

    int count = mpp.size();
    while(j < ss)
    {
        // If word found in map decreae count
        if(mpp.find(s[j])!=mpp.end())
        {
            // Decrease count in map
            mpp[s[j]]--;
                
            // if count of frequency of the character is equal to 0 decrease count  
            if(mpp[s[j]] == 0)
                count--;                   
        }
            
        // Increase window size
        if((j-i+1) < k) j++;
            
        //Window size reached
        else if((j-i+1) == k)
        {
            // All elements found in map
            if(count == 0)
                ans++;
            if(mpp.find(s[i])!=mpp.end())
            {
                mpp[s[i]]++;
                if(mpp[s[i]]==1)
                    count++;
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
	string s = "cbaebabacd";
	string p = "abc";
	
	int ans;
	ans = findAnagrams(s,p);
	cout << ans;
	return 0;
}