class Solution {
public:
    int solve(vector<int> &nums){
        stack<pair<int,int>> s;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int maxi=0;
            while(!s.empty() && s.top().first <= nums[i]) {
                maxi=max(maxi,s.top().second);
                s.pop();
            }
            int steps;
            if(!s.empty())
                steps=maxi+1;
            else
                steps=0;
            ans=max(ans,steps);
            s.push({nums[i],steps});
        }
        return ans;
    }
    int totalSteps(vector<int>& nums) {
        //imagine each value as tower, let's say ith tower's height is i and jth tower's height is j,
        //assume all towers between them are low heights than them, i<j and nums[i] > nums[j] and nums[j] can only be remove after all the elements between them are removed, so the criteria is using decresing/ monostack and storing the maximum step taken to remove a tower between them + 1 i.e max(cnt)+1 as step need to remove jth tower, like wise we generalise algorithm
        return solve(nums);
        stack<pair<int,int>> s;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            while(!s.empty() && s.top().first<= nums[i]){
                cnt=max(cnt,s.top().second);
                s.pop();
            }
            int steps=0;
            if(s.size()){
                steps=cnt+1;
            }
            ans=max(ans,steps);
            s.push({nums[i],steps});
        }
        return ans;
    }
};