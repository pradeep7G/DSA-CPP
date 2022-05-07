class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int startValue=nums[0]>0?1:1-nums[0];
        int sum=startValue;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum<1)
            {
                startValue+=1-sum;
                sum=1;
            }
        }
        return startValue;
    }
};