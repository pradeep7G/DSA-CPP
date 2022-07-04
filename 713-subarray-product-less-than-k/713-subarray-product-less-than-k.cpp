class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int prod=1;
        int res=0;
        for(;i<n;i++){
            prod*=nums[i];
            while(j<=i && prod>=k){
                prod/=nums[j++];
            }
            res+=(i-j+1);
        }
        return res;
    }
};