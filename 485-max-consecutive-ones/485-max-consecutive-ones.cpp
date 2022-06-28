class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;){
            int tmp=0;
            while(i<n && nums[i]==1)
            {
                tmp++;i++;
            }
            i++;
            ans=max(ans,tmp);
        }
        return ans;
    }
};