class Solution {
public:
    int solve(int index,int n,vector<vector<int>> &jobs,vector<int> &dp){
        if(index>=n)
            return 0;
        //can take it or not
        //if we take it we can't take any overlapping jobs, next we should take non-overlapping job with current job
        if(dp[index]!=-1)
            return dp[index];
        int notTake=0+solve(index+1,n,jobs,dp);
        int take=jobs[index][2];
        vector<int> nextJob={jobs[index][1],INT_MIN,INT_MIN};
        int nextIndex=lower_bound(begin(jobs),end(jobs),nextJob)-begin(jobs);
        take+=solve(nextIndex,n,jobs,dp);
        return dp[index]=max(take,notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        //for every job we can choose it , not choose,
        vector<vector<int>> jobs;
        int n=profit.size();
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(begin(jobs),end(jobs));
        vector<int> dp(n,-1);
        return solve(0,n,jobs,dp);
    }
};