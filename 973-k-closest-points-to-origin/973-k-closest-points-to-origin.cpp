class Solution {
public:
    typedef pair<int,pair<int,int>> triplet;
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> v;
        priority_queue<triplet> pq;
        for(auto point:points){
            int dist=(point[0]*point[0])+(point[1]*point[1]);
            if(pq.size()<k){
                pq.push({dist,{point[0],point[1]}});
            }
            else{
                if(pq.top().first>dist){
                  pq.pop();
                  pq.push({dist,{point[0],point[1]}});
                }
            }
        }
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            v.push_back({top.second.first,top.second.second});
        }
        return v;
    }
};