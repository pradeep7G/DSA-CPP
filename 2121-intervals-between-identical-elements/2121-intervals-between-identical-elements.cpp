class Solution {
public:
    typedef long long ll;
    vector<ll> solve(vector<int> &arr){
        unordered_map<ll,vector<ll>> mp;
        int sz=arr.size();
        vector<ll> res(sz);
        for(ll i=0;i<sz;i++)
            mp[arr[i]].push_back(i);
        
        for(auto &[val,nums]:mp){
            int n=nums.size();
            vector<ll> preSums(n);
            partial_sum(begin(nums),end(nums),begin(preSums));
            
            for(ll i=0;i<n;i++){
                if(i==0)
                    res[nums[i]]=preSums[n-1]-preSums[0] - ((n-1)*nums[0]);
                else if(i==n-1)
                    res[nums[i]]=((n-1)*nums[i])-preSums[n-2];
                else
                    res[nums[i]]=preSums[n-1]-preSums[i] - ((n-i-1)*nums[i]) + (i * nums[i])-preSums[i-1];
            }
        }
        return res;
    }
    vector<long long> getDistances(vector<int>& arr) {
        return solve(arr);
        unordered_map<ll,vector<ll>> mp;
        vector<ll> res(arr.size());
        for(ll i=0;i<arr.size();i++)
            mp[arr[i]].push_back(i);
        
        for(auto j:mp){
            ll sum=0;
            vector<ll> val=j.second;
            ll n=val.size();
            vector<ll> pre(n);
            partial_sum(j.second.begin(),j.second.end(),pre.begin());
            //use pref sums to solve
            for(ll i=0;i<n;i++){
                if(i==0){
                    res[val[i]]=abs((pre[n-1]-pre[0])-((n-1)*val[0]));
                }
                else if(i==n-1){
                    res[val[i]]=abs(((n-1)*(val[i])-(pre[n-2])));
                }
                else{
                    res[val[i]]=abs((pre[n-1]-pre[i])-((n-i-1)*val[i]))+abs(pre[i-1]-(i*val[i]));
                }
            }
        }
        return res;
    }
};