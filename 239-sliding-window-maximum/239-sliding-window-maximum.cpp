class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i<k-1)
            {
                pq.push({nums[i],i});
                continue;
            }
            while(!pq.empty() && abs(pq.top().second-i)>=k)
                pq.pop();
            pq.push({nums[i],i});
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};