class Solution {
public:
    int two_binary_search(vector<int> &nums,int target){
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[n-1])
                lo=mid+1;
            else
                hi=mid-1;
        }
        int rot=lo;
        lo=0,hi=rot-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                lo=mid+1;
            else 
                hi=mid-1;
        }
        lo=rot,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                lo=mid+1;
            else 
                hi=mid-1;
        }
        return -1;
    }
    int single_binary_search(vector<int> &nums,int target){
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[n-1])
                lo=mid+1;
            else
                hi=mid-1;
        }
        int rot=lo;
        lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int realmid=(mid+rot)%n;
            if(nums[realmid]==target)
                return realmid;
            else if(nums[realmid]<target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        // int n=nums.size();
        // int low=0,high=n-1;
        // while(low<high){
        //     int mid=low+(high-low)/2;
        //     if(nums[mid]>nums[high])
        //         low=mid+1;
        //     else
        //         high=mid;
        // }
        // int rot=low;
        // int lo=0,hi=n-1;
        // while(lo<=hi){
        //     int mid=lo+(hi-lo)/2;
        //     int realmid=(mid+rot)%n;
        //     if(nums[realmid]==target)
        //         return realmid;
        //     if(nums[realmid]<target)
        //         lo=mid+1;
        //     else
        //         hi=mid-1;
        // }
        // return -1;
        return single_binary_search(nums,target);
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mid>0 && nums[mid-1]>nums[mid]){
                lo=mid;
                break;
            }
            if(nums[mid]>nums[hi]){
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        int pivot=lo;
        lo=0,hi=n-1;
        //assume start as pivot and again to binary search to find target; or do two binary searches in first part and second part.
        
        // while(lo<=hi){
        //     int mid=lo+(hi-lo)/2;
        //     int realmid=(mid+pivot)%n;
        //     if(nums[realmid]==target)
        //     {
        //         return realmid;
        //     }
        //     if(nums[realmid]<target){
        //         lo=mid+1;
        //     }
        //     else
        //         hi=mid-1;
        // }
        // return -1;
        int ret=lower_bound(nums.begin(),nums.begin()+pivot,target)-nums.begin();
        if(ret>=0 && ret<n && nums[ret]==target)
            return ret;
        ret=lower_bound(begin(nums)+pivot,end(nums),target)-begin(nums);
        if(ret>=0 && ret<n &&  nums[ret]==target)
            return ret;
        return -1;
    }
};