#include <vector>
#include "bits/stdc++.h"

using namespace std;

vector<int> printFirstNegativeInteger(int A[], int N, int K) 
{
         int i=0;
         int j=0;
         
         vector<int> ans;
         list<int> l;
         
         while (j<N)
         {
            if (A[j]<0) 
              l.push_back(A[j]);
            
            if (j-i+1<K) j++;
            
            else if ((j-i+1)==K)
            {
              if (l.size()==0)
                ans.push_back(0);
              else
                ans.push_back(l.front());
              if(A[i]<0)
                l.pop_front();
              i++;
              j++;
            }
          }
          
          return ans;
}

int main()
{
	vector<int> ans;
	int nums[] = {12, -1, -7, 8, -15, 30, 16, 28};
	ans = printFirstNegativeInteger(nums,8,3);
	for(int i=0; i<ans.size();i++)
	{
		cout << ans[i]<<" ";
	}
	return 0;
}