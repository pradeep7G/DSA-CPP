class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        //absolute diff between any two elements less than limit means diff between max and min
        //how do we get longest one
        //use monoqueue i.e deque s for having max and min element
        //and do sliding window with them
        deque<int> min_dq,max_dq;
        int n=nums.size();
        int left=0,right=0;
        int res=1;
        for(;right<n;right++){
            while(!max_dq.empty() && max_dq.back()<nums[right])
                max_dq.pop_back();
            while(!min_dq.empty() && min_dq.back()>nums[right])
                min_dq.pop_back();
            max_dq.push_back(nums[right]);
            min_dq.push_back(nums[right]);
            while(!max_dq.empty() && !min_dq.empty() && (max_dq.front() - min_dq.front())>limit){
                if(max_dq.front()==nums[left])
                    max_dq.pop_front();
                if(min_dq.front()==nums[left])
                    min_dq.pop_front();
                left++;
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};