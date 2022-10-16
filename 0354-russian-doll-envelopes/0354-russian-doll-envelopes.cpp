class Solution {
public:
    int solve1(vector<vector<int>> &env){
        int n=env.size();
        sort(begin(env),end(env),[&](const vector<int> &a,const vector<int> &b){
           return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(env[j][0]<env[i][0] and env[j][0]<env[i][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(begin(dp),end(dp));
    }
    int solve2(vector<vector<int>> &env){
        int n=env.size();
        sort(begin(env),end(env),[&](const vector<int> &a,const vector<int> &b){
           return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });
        vector<int> dp;
        for(int i=0;i<n;i++){
            auto it=lower_bound(begin(dp),end(dp),env[i][1]);
            if(it==dp.end())
                dp.push_back(env[i][1]);
            else if(env[i][1] < *it)
                *it=env[i][1];
        }
        return dp.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //LIS Pattern
        return solve2(envelopes);
    }
};