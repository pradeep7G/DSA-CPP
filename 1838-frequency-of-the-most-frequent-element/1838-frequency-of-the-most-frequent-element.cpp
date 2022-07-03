class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int left=0,right=0;
        long long sum=0;
        int res=0;
        for(;right<n;right++){
            sum+=nums[right];
            long long diff=((long long)(right-left+1)*(long long)nums[right]);
            diff=diff-sum;
            while(left<=right & diff>k){
                diff-=(nums[right]-nums[left]);
                sum-=nums[left++];
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};