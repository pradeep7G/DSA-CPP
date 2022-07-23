class Solution {
public:
    struct compare {
        bool operator()(pair<int,int> &a,pair<int,int> &b){
            if(a.first==b.first)
                return a.second < b.second;
            return a.first < b.first;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        vector<pair<int,int>> nums;
        for(int i=0;i<n;i++){
            int count=0;
            for(auto col:mat[i]){
                if(col==0)break;
                count++;
            }
            nums.push_back({count,i});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq; //min_heap , 
        for(auto i:nums)
        {
            pq.push(i);
            if(pq.size()>k)
             pq.pop();
        }
        vector<int> res;
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            res.push_back(top.second);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};