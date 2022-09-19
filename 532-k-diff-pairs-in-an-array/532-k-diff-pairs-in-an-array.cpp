class Solution {
public:
    int twoPointers(vector<int> &nums,int k){
        int n=nums.size();    
        sort(begin(nums),end(nums));
        int i=0,j=1;
        int ans=0;
        for(;i<n and j<n;){
            if(i==j || nums[j]-nums[i] < k){
                j++;
                continue;
            }
            if(nums[j]-nums[i] == k){
                ans++;
                j++;
                while(j<n and nums[j]==nums[j-1])
                    j++;
            }
            i++;
        }
        return ans;
    }
    int solve(vector<int> &nums,int k){
        return twoPointers(nums,k);
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto i:nums)
            mp[i]++;
        int ans=0;
        for(auto [num,count]:mp){
            if(mp.count(num+k)){
                if(k==0)
                    if(mp[num+k]>1)
                     ans+=1;
                else
                     ans+=1;
            }
        }
        return ans;
    }
    // int twoPointers(vector<int> &nums,int k){
    //     int n=nums.size();
    //     sort(begin(nums),end(nums));
    //     int i=0,j=1;
    //     int ans=0;
    //     for(;j<n && i<n;){
    //         if(i==j || nums[j]-nums[i]<k)
    //         {
    //             j++;
    //             continue;
    //         }
    //         if(nums[j]-nums[i]==k){
    //             ans++;
    //             j++;
    //             while(j<n && nums[j]==nums[j-1])
    //                 j++;                        //remove repeated;
    //         }
    //         i++;
    //         while(i<n && nums[i]==nums[i-1])i++;
    //     }
    //     return ans;
    // }
    int findPairs(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());//if we use hashmap no need to sort, we can directly iterate through hashmap elements TC: O(N),SC:O(N); if we use sorting and two pointers TC:O(NlogN);SC:O(1)
        return solve(nums,k);
        return twoPointers(nums,k);
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto i:nums)
            mp[i]++;
        int ans=0;
        for(auto x:mp){
            if(mp.find(x.first+k)!=mp.end()){
                if(k==0 && mp[x.first]>1){
                    ans+=1;
                }
                else if(k!=0){
                    ans+=1;
                }
            }
        }
        return ans;
    }
};