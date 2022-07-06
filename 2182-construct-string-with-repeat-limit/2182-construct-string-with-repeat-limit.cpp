class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>> pq;
        unordered_map<char,int> mp;
        for(auto c:s)
            mp[c]++;
        for(auto i:mp)
            pq.push({i.first,i.second});
        string ans="";
        while(!pq.empty()){
            auto val=pq.top();
            pq.pop();
            if(val.second > repeatLimit){
                int r=repeatLimit;
                val.second-=repeatLimit;
                while(r--){
                    ans+=val.first;
                }
                if(pq.empty())
                    return ans;
                ans+=pq.top().first;
                auto remove=pq.top();
                pq.pop();
                remove.second-=1;
                if(remove.second>=1)
                {
                    pq.push(remove);
                }
                pq.push(val);
            }
            else{
                int r=val.second;
                while(r--){
                    ans+=val.first;
                }
            }
        }
        return ans;
    }
};