class Solution {
public:
    typedef long long ll;
    int shortestSubarray(vector<int>& nums, int k) {
        //Attention: if all elements in nums are +ve then it's just sliding window on nums, BUT HERE THERE CAN BE NEGATIVE Elements, 
        //monotonic decreasing queue??
        //bruteforce:Time:O(N^2),Space:O(N);
        //can we do better??;
        //Yes, we use monoqueue decreasing,since it'contains -ve elements we can't apply sliding window,but if we do prefsums and maintain monoqueue decreasing, we can efficiently check subarray's with sum atleast k
        int n=nums.size();
        vector<ll> pref(n,0);//we can use existing nums array to build prefix sums, but it would so bad to look, if we are explicitly asked to do so, do then!!
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=nums[i]+pref[i-1];
        }
        int ans=n+1;
        deque<int> dq;
        for(int i=0;i<n;i++){
            if(pref[i]>=k){
                ans=min(ans,i+1);
            }
            while(!dq.empty() && pref[i]-pref[dq.front()]>=k)
            {
                ans=min(ans,i-dq.front());
                dq.pop_front();
            }
            //remove invalid prefix sum ranges
            while(!dq.empty() && pref[i]<=pref[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        if(ans>n)
            return -1;
        return ans;
    }
};