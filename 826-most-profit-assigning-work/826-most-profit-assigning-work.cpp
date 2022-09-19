class Solution {
public:
    int solve(vector<int> &difficulty,vector<int> &profit,vector<int> &worker){
        vector<pair<int,int>> jobs;
        int m=profit.size(),n=worker.size();
        for(int i=0;i<m;i++)
            jobs.push_back(make_pair(difficulty[i],profit[i]));
        sort(begin(jobs),end(jobs));
        sort(begin(worker),end(worker));
        int best=0,maxProfit=0;
        for(int i=0,j=0;i<n;i++){
            while(j<m and jobs[j].first <=worker[i]){
                best=max(best,jobs[j].second);
                j++;
            }
            maxProfit+=best;
        }
        return maxProfit;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        return solve(difficulty,profit,worker);
        vector<pair<int,int>> jobs;
        int m=profit.size(),n=worker.size();
        for(int i=0;i<m;i++){
            jobs.push_back({difficulty[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());
        int best=0;
        int maxProfit=0;
        int j=0;
        //two pointers to find worker's best possible profit
        for(int i=0;i<n;i++){
            while(j<m && jobs[j].first <= worker[i]){
                best=max(best,jobs[j].second);
                j++;
            }
            maxProfit+=best;
        }
        return maxProfit;
    }
};