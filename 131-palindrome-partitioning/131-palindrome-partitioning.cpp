class Solution {
public:
    vector<vector<string>> res;
    vector<string> sol;
    bool ispal(string s,int i,int j){
        for(;i<j;i++,j--){
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
    void solve(int start,int n,string s){
        if(start>=n){
            res.push_back(sol);
            return ;
        }
        for(int i=start;i<n;i++){
            if(ispal(s,start,i)){
                sol.push_back(s.substr(start,i-start+1));
                solve(i+1,n,s);
                sol.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        res.clear();sol.clear();
        solve(0,s.length(),s);
        return res;
    }
};