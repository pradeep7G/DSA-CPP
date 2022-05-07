class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // cout<<next_permutation(begin(nums),end(nums))<<"\n";
        //find the longest weakly decreaing suffix (i+1,end), start index = i;
        //and then find the longest index j such that nums[j]>=nums[i]
        // and then swap nums[i],nums[j]
        //and then reverse the suffix (i+1,end)
        
        //Time O(N), Space O(1)
        int pivot=-1,n=nums.size();
        
        //step-1
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<nums[i+1])
                pivot=i;
        }
        //setp-2
        if(pivot==-1)
            return reverse(begin(nums),end(nums));
        int minNumIndexSuf=-1;
        for(int i=pivot+1;i<n;i++)
        {
            if(nums[i]>nums[pivot])
                minNumIndexSuf=i;
        }
        //step-3
        swap(nums[pivot],nums[minNumIndexSuf]);
        //step-4
        reverse(begin(nums)+pivot+1,end(nums));
        
    }
};