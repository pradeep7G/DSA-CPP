// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	   
	    int n=nums.size();
	    vector<int> temp(nums.begin(),nums.end());
	    sort(temp.begin(),temp.end());
	    unordered_map<int,int> mp;
	    for(int i=0;i<n;i++)
	    mp[nums[i]]=i;
	    int count=0;
	    for(int i=0;i<n;i++){
	        if(nums[i]!=temp[i]){
	            int ele=nums[i];
	            swap(nums[i],nums[mp[temp[i]]]);
	            mp[ele]=mp[temp[i]];
	            mp[temp[i]]=i;
	            count++;
	        }
	    }
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends