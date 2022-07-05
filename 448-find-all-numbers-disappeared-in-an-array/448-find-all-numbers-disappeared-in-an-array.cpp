class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //intuitive approach, mark -ve for element i , if dups appear then we don't mark again since already marked -ve. so finally the indices of elements which are not marked are the digits we are missing in the array;
        
        //Key: array contains values only from [1,n].
        //Time O(n), space O(1) without solution storage space, O(n) with solution storage space
        // vector<int> ans;
        int n=nums.size();
        // for(int i=0;i<n;i++)
        // {
        //     int m=abs(nums[i])-1;
        //     nums[m]=nums[m]>0?-nums[m]:nums[m];
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i] > 0)
        //         ans.push_back(i+1);
        // }
        // return ans;
        
        //cyclic sort
        int i=0;
        while(i<n){
            if(nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            else
                i++;
        }
        vector<int> res;
        for(int i=0;i<n;i++)
            if(nums[i]!=i+1)
                res.push_back(i+1);
        return res;
        
        //with using extra space isPresent[] though overall space will O(n) as we need to store sols
        //Time O(n), O(n) with solution storage space
        /*
        vector<bool> isPresent(n+1,false);vector<int> ans;
        for(auto x:nums)
            isPresent[x]=true;
        for(int i=1;i<=n;i++)
            if(!isPresent[i])ans.push_back(i);
        return ans;
        */
    }
};