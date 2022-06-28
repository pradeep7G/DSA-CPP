class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int lo=0,hi=n-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(mid==0 && nums[mid]!=nums[mid+1])
                return nums[mid];
            else if(mid==n-1 && nums[mid]!=nums[mid-1])
                return nums[mid];
            else if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            else{
                if(nums[mid]==nums[mid+1])
                {
                    int right=n-1-mid-1;
                    int left=mid-1;
                    if(right%2==1){
                        lo=mid+2;
                    }
                    else{
                        hi=mid-1;
                    }
                }
                else if(nums[mid]==nums[mid-1]){
                    int right=n-1-mid;
                    int left=mid-2;
                    if(right%2==1){
                        lo=mid+1;
                    }
                    else{
                        hi=mid-2;
                    }
                }
            }
        }
        return nums[lo];
    }
};