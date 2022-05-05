class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //intuitive approach, mark -ve for element i , if dups appear then we don't mark again since already marked -ve. so finally the indices of elements which are not marked are the digits we are missing in the array;
        
        //Key: array contains values only from [1,n].
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int m=abs(nums[i])-1;
            nums[m]=nums[m]>0?-nums[m]:nums[m];
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i] > 0)
                ans.push_back(i+1);
        }
        return ans;
    }
};