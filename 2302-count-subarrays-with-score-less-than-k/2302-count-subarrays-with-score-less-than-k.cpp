class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count=0;
        long long sum=0;
        int n=nums.size();
        long long score;
        for(int left=0,right=0;left<n && right<n;right++){
            sum+=nums[right];
            score=sum*(right-left+1);
            while(score>=k && left<=right){
                sum-=nums[left++];
                score=sum*(right-left+1);
            }
            if(score<k)
            count+=right-left+1;
        }
        return count;
    }
};