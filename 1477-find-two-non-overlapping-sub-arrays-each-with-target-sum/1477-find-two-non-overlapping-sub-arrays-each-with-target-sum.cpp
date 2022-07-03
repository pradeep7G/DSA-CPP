class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> pre(n,0),suf(n,0);
        int res=INT_MAX;
        solve(arr,target,pre);
        solve({arr.rbegin(),arr.rend()},target,suf);
        for(int i=0;i<n-1;i++){
            if(pre[i]!=0 && suf[n-i-2]!=0)
             res=min(res,pre[i]+suf[n-i-2]);
        }
        if(res==INT_MAX)
            return -1;
        return res;
    }
    void solve(vector<int> arr,int target,vector<int> &presuf){
        int n=arr.size();
        int left=0,right=0;
        int res=INT_MAX;
        long long sum=0;
        for(;right<n;right++){
            sum+=arr[right];
            while(left<=right && sum>target){
                sum-=arr[left++];
            }
            if(sum==target){
                res=min(res,right-left+1);
            }
            if(res==INT_MAX)
                presuf[right]=0;
            else
                presuf[right]=res;
        }
    }
};