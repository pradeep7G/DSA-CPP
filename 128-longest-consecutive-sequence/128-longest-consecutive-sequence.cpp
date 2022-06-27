class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(begin(nums),end(nums));
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
           if(s.find(nums[i])==s.end())
                continue;
            int prev=nums[i]-1,next=nums[i]+1;
            while(s.find(prev)!=s.end())
                s.erase(prev--);
            while(s.find(next)!=s.end())
                s.erase(next++);
            ans=max(ans,next-prev-1);
        }
        return ans;
    }
};