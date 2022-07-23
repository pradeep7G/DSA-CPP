class Solution {
public:
    typedef pair<int,int> t;
    vector<int> solvePractice(vector<vector<int>> &intervals,vector<int> &queries){
        sort(begin(intervals),end(intervals));
        map<int,int> mp;
        priority_queue<t,vector<t>,greater<t>> pq;
        vector<t> q;
        int n=queries.size(),m=intervals.size();
        for(int i=0;i<n;i++)
            q.push_back({queries[i],i});
        sort(begin(q),end(q));
        int i=0;
        vector<int> res(n,-1);
        for(auto &[query,index]:q){
            for(;i<m && intervals[i][0]<=query;i++){
                int len=intervals[i][1]-intervals[i][0]+1;
                pq.push({intervals[i][1],len});
                mp[len]++;
            }
            //remove invalid intervals and their length length entries in map
            while(!pq.empty() && pq.top().first<query){
                auto [end,len]=pq.top();
                pq.pop();
                mp[len]--;
                if(mp[len]==0)
                    mp.erase(len);
            }
            if(mp.size())
                res[index]=mp.begin()->first;
        }
        return res;
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        return solvePractice(intervals,queries);
        sort(begin(intervals),end(intervals));
        map<int,int> mp;
        priority_queue<t,vector<t>,greater<t>> pq;
        vector<t> q;
        int n=queries.size(),m=intervals.size();
        for(int i=0;i<n;i++)
            q.push_back({queries[i],i});
        sort(begin(q),end(q));
        int i=0;
        vector<int> res(n,-1);
        for(auto &[query,index]:q){
            for(;i<m && intervals[i][0]<=query;i++){
                int len=intervals[i][1]-intervals[i][0]+1;
                pq.push({intervals[i][1],len});
                mp[len]++;
            }
            while(pq.size() && pq.top().first<query){
                auto [end,len]=pq.top();
                pq.pop();
                mp[len]--;
                if(mp[len]==0)
                    mp.erase(len);
            }
            if(mp.size())
                res[index]=mp.begin()->first;
        }
        return res;
    }
};