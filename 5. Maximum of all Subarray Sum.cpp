#include "bits/stdc++.h"
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	int i=0;
	int j=0;
	list<int> l;
	vector<int> ans;
	
	// Window size greater than array size / equal
	if(k > nums.size())
	{
		ans.push_back(*max_element(l.begin(),l.end()));
		return ans;
	}
	
	// Traverse the array
	while(j< nums.size())
	{
		// Current element is greater than the elements at the back pop each element less than the current element
		while(l.size()>0 && l.back()<nums[j])
			l.pop_back();
		l.push_back(nums[j]);
		
		// Window size is less than size of required window increase it
		if((j-i+1) < k) j++;
		
		// Window size reached 		
		if((j-i+1)==k)
		{
			// Store maximum at front in the answer
			ans.push_back(l.front());
			
			// Maximum at start of the window (pop from the list)
			if(nums[i]==l.front())
				l.pop_front();
			
			// Slide the window
			i++;
			j++;
		}
	}
}
int main()
{
	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	vector<int> ans;
	ans = maxSlidingWindow(nums,3);
	for(int i : ans)
	{
		cout << i;
	}
}