class Solution {
public:
    int mod=1e9+7;
    typedef long long ll;
    int rev(int num){
        int ans=0;
        while(num){
            int digit=num;
            ans=ans*10+(digit%10);
            num=digit/10;
        }
        return ans;
    }
    int solve(vector<int> &nums){
        //Asked in Navi.
        unordered_map<ll,ll> mp;
        int n=nums.size();
        ll ans=0;
        for(int i=0;i<n;i++){
            int num=nums[i]-rev(nums[i]);
            ans=(ans+mp[num])%mod;
            mp[num]++;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        return solve(nums);
        unordered_map<long long,long long> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]-rev(nums[i])]++;
        }
        long long ans=0;
        for(auto i:mp){
            ans=(ans+(i.second*(i.second-1LL))/2)%mod;
        }
        return ans%mod;
    }
};