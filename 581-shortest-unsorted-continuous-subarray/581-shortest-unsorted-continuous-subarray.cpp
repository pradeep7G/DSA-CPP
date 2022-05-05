class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //Time O(NLogN),Space O(N)
//         vector<int> sortedNums(nums);
//         sort(begin(nums),end(nums));
        int n=nums.size();
//         int start=-1,end=-1;
//         for(int i=0;i<n;i++)
//         {
//             if(start==-1 && sortedNums[i] != nums[i]){
//                 start=i;
//             }
//             if(start!=-1 && sortedNums[i] != nums[i])
//             {
//                 end=i;
//             }
//         }
//         if(start==-1 && end==-1)return 0;
//         return end-start+1;
        
        //Time O(N)
        int max=nums[0],end=-1;
        for(int i=1;i<n;i++)
        {
            if(max>nums[i])
            {
                end=i;
            }
            else{
                max=nums[i];
            }
        }
        int min=nums[n-1],start=0;
        for(int i=n-2;i>=0;i--)
        {
            if(min<nums[i])
            {
                start=i;
            }
            else{
                min=nums[i];
            }
        }
        return end-start+1;
    }
};