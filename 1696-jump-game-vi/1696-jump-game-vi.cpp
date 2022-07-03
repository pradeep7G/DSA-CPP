class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        //monoqueue
        deque<int> dq;
        long long cur=0;
        for(int i=n-1;i>=0;i--){
            cur=nums[i]+(dq.empty()?0:nums[dq.front()]);
            while(!dq.empty() && nums[dq.back()]<cur)
                dq.pop_back();
            dq.push_back(i);
            while(!dq.empty() && dq.front()-i>=k){
                dq.pop_front();
            }
            nums[i]=cur;
        }
        return cur;
    }
};