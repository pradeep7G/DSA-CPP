class Solution {
public:
    //TLE O(2^n) time, O(n) space;
    int bruteforce(int p,vector<int> &nums,int sum){
        if(p==nums.size()){
            return sum==0;
        }
        return bruteforce(p+1,nums,sum+nums[p]) + bruteforce(p+1,nums,sum-nums[p]);
    }
    //2 brute with hashmap
    unordered_map<string,int> mp; //first observation we don't need to maintain hashmap for bruteforce as at every step the string formed will be unique and when we reached it will be unique for every solution
    void dfs(string &s,int i,int sum,vector<int> &nums,int target){
        if(i==nums.size()){
            if(sum!=target){
                return ;
            }
            else{
                mp[s]++;
                return ;
            }
        }
        //add +
        s.push_back('+');
        s.push_back(char(nums[i]));
        dfs(s,i+1,sum+nums[i],nums,target);
        //add -
        s.pop_back();
        s.pop_back();
        s.push_back('-');
        s.push_back(char(nums[i]));
        dfs(s,i+1,sum-nums[i],nums,target);
        return ;
    }
    //overlapping sub-problems occur at state with same start index i and same sum, i.e (i+1,sum) is already computed then we memoize it, for ex: 0,0,0 .... 0,1 and target=1, for this Tc: (i+1,sum) state is repeating, we compute this in first recursion recurrence relation and then we reuse it as the ans would be same as (i+1,sum) is already occured
    int topDown(int i,vector<int> &nums,int sum,vector<unordered_map<int,int>> &memo){
        if(i==nums.size()){
            return sum==0;
        }
        if(memo[i].find(sum)!=memo[i].end()){
            return memo[i][sum];
        }
        return memo[i][sum]=topDown(i+1,nums,sum+nums[i],memo)+topDown(i+1,nums,sum-nums[i],memo);
    }
    int solve1(vector<int> &nums,int target){
        int n=nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(auto &p:dp[i]){
                dp[i+1][p.first+nums[i]]+=p.second;
                dp[i+1][p.first-nums[i]]+=p.second;
            }
        }
        return dp[n][target];
    }
    int topDn(int ind,vector<int> &nums,int target,vector<vector<int>> &dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][target]!=-1)
            return dp[ind][target];
       int notTake=topDn(ind+1,nums,target,dp);
       int take=0;
       if(nums[ind]<=target)
           take=topDn(ind+1,nums,target-nums[ind],dp);
        return dp[ind][target]=take+notTake;
    }
    int solve2(vector<int> &nums,int target){
        int n=nums.size();
        int totSum=accumulate(begin(nums),end(nums),0LL);
        if((totSum-target)&1)
            return 0;
        int tot=(totSum-target)/2;
        vector<vector<int>> dp(n,vector<int>(tot+1,-1));
        return topDn(0,nums,tot,dp);
    }
    int bottomUp(vector<int>& nums, int target){
        int n=nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(auto &p:dp[i]){
                dp[i+1][p.first+nums[i]]+=p.second;
                dp[i+1][p.first-nums[i]]+=p.second;
            }
        }
        return dp[n][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // nums length is 2 pow 20
    //1
        //return bruteforce(0,nums,target);
    //2
        // mp.clear();
        // int n=nums.size();
        // string str="";
        // dfs(str,0,0,nums,target);
        // return mp.size();
    //3 Memoization
        // int n=nums.size();
        // vector<unordered_map<int,int>> memo(n);
        // return topDown(0,nums,target,memo);
    //4 Bottom Up
        return solve1(nums,target);
        return solve2(nums,target);
        return bottomUp(nums,target);
    }
};