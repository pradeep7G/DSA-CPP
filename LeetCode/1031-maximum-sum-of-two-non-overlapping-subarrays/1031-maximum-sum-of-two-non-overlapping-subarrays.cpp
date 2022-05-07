class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(find(nums,firstLen,secondLen),find(nums,secondLen,firstLen));
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