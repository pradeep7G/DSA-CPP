class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
      // deque<int> dq;
      // int n=nums.size();
      // int res=nums[0];
      // for(int i=0;i<n;i++){
      //     nums[i]=nums[i]+(dq.empty()?0:dq.front());
      //     res=max(res,nums[i]);
      //     while(!dq.empty() && dq.back()<nums[i])
      //         dq.pop_back();
      //     if(nums[i]>0)
      //         dq.push_back(nums[i]);
      //     while(i-k>=0 && !dq.empty() && dq.front()==nums[i-k])
      //         dq.pop_front();
      // }
      // return res;
        deque<int> q;
        int res = A[0];
        for (int i = 0; i < A.size(); ++i) {
            A[i] += q.size() ? q.front() : 0;
            res = max(res, A[i]);
            while (q.size() && A[i] > q.back())
                q.pop_back();
            if (A[i] > 0)
                q.push_back(A[i]);
            if (i >= k && q.size() && q.front() == A[i - k])
                q.pop_front();
        }
        return res;
    }
};