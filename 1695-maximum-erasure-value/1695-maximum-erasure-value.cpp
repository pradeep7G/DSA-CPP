class Solution {
public:
    int solve(vector<int> &nums){
        int sum=0;
        int n=nums.size();
        int left=0,right=0,res=0;
        unordered_map<int,int> mp;
        for(;right<n;right++){
            sum+=nums[right];
            mp[nums[right]]++;
            while(mp.size()<right-left+1){
                int num=nums[left++];
                sum-=num;
                mp[num]--;
                if(mp[num]==0)
                    mp.erase(num);
            }
            if(mp.size()==right-left+1)
            res=max(res,sum);
        }
        return res;
    }
    int maximumUniqueSubarray(vector<int>& nums) {
        //subarray containing unqiue elements and score is it's sum;
        return solve(nums);
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