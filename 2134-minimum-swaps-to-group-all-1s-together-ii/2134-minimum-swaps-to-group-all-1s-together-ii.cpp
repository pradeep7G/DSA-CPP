class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int res=0;
        //we go and prune 0 .. n-1 and also circular possiblities n-2 to end while left==n+1;
        int left=0,right=0,n=nums.size();
        int ones=0,count=0;
        for(int i=0;i<n;i++){
            count+=(nums[i]==1);
        }
        for(;right<2*n;right++){
            ones+=(nums[right%n]==1);
            if(right<count-1)
                continue;
            res=max(res,ones);
            ones-=(nums[left%n]==1);
            left++;
        }
        return count-res;
    }
};