class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high])
                low=mid+1;
            else
                high=mid;
        }
        int rot=low;
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int realmid=(mid+rot)%n;
            if(nums[realmid]==target)
                return realmid;
            if(nums[realmid]<target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return -1;
    }
};