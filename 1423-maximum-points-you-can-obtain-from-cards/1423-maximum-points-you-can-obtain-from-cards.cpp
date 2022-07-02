class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        //min subarray of size n-k
        int n=cp.size();
        int sum=0,total_sum=0,res=INT_MAX;
        k=n-k;
        for(int i=0;i<n;i++){
            total_sum+=cp[i];
            sum+=cp[i];
            if(i<k-1)
                continue;
            res=min(res,sum);
            sum-=cp[i-k+1];
        }
        if(k==0)
            return total_sum;
        if(res==INT_MAX)
            return -1;
        return total_sum-res;
    }
};