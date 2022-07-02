class Solution {
public:
    int solve(vector<int> &nums,int len1,int len2){
        int sum_l=0,sum_r=0;
        for(int i=0;i<len1+len2;i++){
            if(i<len1)
                sum_l+=nums[i];
            else
                sum_r+=nums[i];
        }
        int max_l=sum_l,ans=sum_l+sum_r;
        for(int i=len1+len2;i<nums.size();i++){
            sum_r=sum_r+nums[i]-nums[i-len2];
            sum_l=sum_l+nums[i-len2]-nums[i-len2-len1];
            max_l=max(max_l,sum_l);
            ans=max(ans,max_l+sum_r);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(solve(nums,firstLen,secondLen),solve(nums,secondLen,firstLen));
        // return max(find(nums,firstLen,secondLen),find(nums,secondLen,firstLen));
    }
    int find(vector<int>& nums, int firstLen, int secondLen)
    {
        int sumL=0,sumM=0;
        for(int i=0;i<firstLen+secondLen;i++)
        {
            if(i<firstLen)sumL+=nums[i];
            else{
                sumM+=nums[i];
            }
        }
        int maxL=sumL,ans=sumL+sumM;
        for(int i=firstLen+secondLen;i<nums.size();i++)
        {
            sumM+=nums[i]-nums[i-secondLen];
            sumL+=nums[i-secondLen]-nums[i-firstLen-secondLen];
            maxL=max(maxL,sumL);
            ans=max(ans,maxL+sumM);
        }
        return ans;
    }
};