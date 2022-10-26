class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>> &val){
        int n=val.size();
        sort(begin(val),end(val));
        vector<vector<int>> res;
        res.push_back(val[0]);
        for(int i=1;i<n;i++){
            if(val[i][0] <= res.back()[1]){
                res.back()[1]=max(res.back()[1],val[i][1]);
            }
            else{
                res.push_back(val[i]);
            }
        }
        return res;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //we sort the intervals by start_i;
        //s1,e1; s2,e2; s3,e3
        //if e1<s2 then we push s2, because s2 doesn't overlap with s1
        //else e1>=s2 then we merge since s2 overlaps with s1,e1
        return solve(intervals);
        int n=intervals.size();
        sort(begin(intervals),end(intervals));
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=res.back()[1]){
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};