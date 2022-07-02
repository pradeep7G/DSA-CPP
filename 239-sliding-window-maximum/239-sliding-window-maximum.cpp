class Solution {
public:
    // O(N)??
    vector<int> solve(vector<int> &nums,int k){
        deque<int> dq;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for(int i=k;i<n;i++){
            while(!dq.empty() && i-dq.front()>=k)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //O(NLOGN)
        return solve(nums,k);
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