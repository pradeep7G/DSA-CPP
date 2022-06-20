class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> prev(begin(nums),end(nums));
        sort(begin(nums),end(nums));
        int start=-1,end=-1;
        for(int i=0;i<nums.size();i++){
            if(prev[i]!=nums[i]){
                if(start==-1)
                {
                    start=i;
                }
                end=i;
            }
        }
        if(start==-1 && end==-1)
            return 0;
        return end-start+1;
    }
};