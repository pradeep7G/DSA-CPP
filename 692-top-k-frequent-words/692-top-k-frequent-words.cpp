class Solution {
public:
    struct compare {
        bool operator()(const pair<int,string> &a,const pair<int,string> &b){
            if(a.first!=b.first)
                return a.first > b.first;
            return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int> mp;
        for(auto s:words)
            mp[s]++;
        priority_queue<pair<int,string>> pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        vector<string> v;
        while(!pq.empty() && v.size()<k){
            auto top=pq.top();
            vector<string> tmp;
            while(!pq.empty() && top.first==pq.top().first){
                tmp.push_back(pq.top().second);
                pq.pop();
            }
            sort(tmp.begin(),tmp.end());
            for(int i=0;i<tmp.size() && v.size()<k;i++){
                v.push_back(tmp[i]);
            }
        }
        return v;
    }
};