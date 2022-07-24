class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        //kth smallest distance
        //no.of pairs binary search on distance and count no.of pairs such that distance <= mid, nums[j]-nums[i]<=mid; cnt+=j-i-1,we computed for i=0, now for pairs with i=2, if we again try from start it will O(n^2) so we need to reduce the complexity so we use the advantage of sortedness, we can use classic two pointers approach
        sort(begin(nums),end(nums));
        int n=nums.size();
        int lo=0,hi=nums[n-1]-nums[0];
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int count=0;
            for(int i=0,j=0;i<n;i++){
                while(j<n && nums[j]-nums[i]<=mid)j++;
                count+=j-i-1;
            }
            if(count<k){
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        return lo;
    }
};