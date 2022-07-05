class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //with modifying the array we can do with -ve sign marking or cyclic sort both are identical
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[abs(nums[i])-1]<0)
        //         return abs(nums[i]);
        //     nums[abs(nums[i])-1]*=-1;
        // }
        // return -1;
        
        //Without modifying the array
        //fast ans slow pointers, same as linked list loop, here we can loop because elements are in range [1,n] and indices are in [0,n];
        int slow=nums[0],fast=nums[nums[0]];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast){
                fast=nums[0];
                slow=nums[slow];
                while(slow!=fast){
                    slow=nums[slow];
                    fast=nums[fast];
                }
                return slow;
            }
        }
        return slow;
    }
};