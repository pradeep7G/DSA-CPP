class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //Time O(NLogN),Space O(N)
        vector<int> sortedNums(nums);
        sort(begin(nums),end(nums));
        int n=nums.size();
        int start=-1,end=-1;
        for(int i=0;i<n;i++)
        {
            if(start==-1 && sortedNums[i] != nums[i]){
                start=i;
            }
            if(start!=-1 && sortedNums[i] != nums[i])
            {
                end=i;
            }
        }
        if(start==-1 && end==-1)return 0;
        return end-start+1;
    }
};