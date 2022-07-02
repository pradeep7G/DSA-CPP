class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //subarray containing unqiue elements and score is it's sum;
        int sum=0;
        int n=nums.size();
        int left=0,right=0,res=0;
        unordered_map<int,int> mp;
        for(;right<n;right++){
            sum+=nums[right];
            if(mp.find(nums[right])!=mp.end()){
                if(left<=mp[nums[right]]){
                  while(left<=mp[nums[right]]){
                      sum-=nums[left++];
                  }
                }
            }
            mp[nums[right]]=right;
            res=max(res,sum);
        }
        return res;
    }
};