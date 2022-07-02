class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;
        int left=0,right=0,count=0,odd=0;
        for(;right<n;right++){
            if(nums[right]&1){
                odd++;
                if(odd>=k){
                    count=1;
                    while(!(nums[left++]&1)){
                        count++;
                    }
                    ans+=count;
                }
            }
            else if(odd>=k)
                ans+=count;
        }
        return ans;
    }
};