class Solution {
public:
    int solve(vector<vector<int>> &events){
        priority_queue<vector<int>> pq;
        int max_value=0,ans=0;
        sort(begin(events),end(events));//sort by start time
        for(auto e:events){
            while(!pq.empty() && -pq.top()[0]<e[0]){
                max_value=max(max_value,pq.top()[2]);
                pq.pop();
            }
            ans=max(ans,e[2]+max_value);
            pq.push({-e[1],e[0],e[2]});
        }
        return ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
       return solve(events);
    }
};