class Solution {
public:
    vector<string> res;
    void dfs(int idx,int n,string &s){
        if(idx>=n){
            res.push_back(s);
            return ;
        }
        
        if(!isalpha(s[idx])){
            dfs(idx+1,n,s);
            return ;
        }
        //not convert
        dfs(idx+1,n,s);
        //convert
        char ch=s[idx];
        s[idx]=isupper(ch)?tolower(ch):toupper(ch);
        dfs(idx+1,n,s);
        s[idx]=ch; //backtrack
    }
    vector<string> bfs(string &s){
        vector<string> res;
        int n=s.length();
        res.push_back(s);
        for(int i=0;i<n;i++){
            if(!isalpha(s[i]))
                continue;
            int size=res.size();
            for(int j=0;j<size;j++){
                vector<char> ch(res[j].begin(),res[j].end());
                ch[i]=isupper(ch[i])?tolower(ch[i]):toupper(ch[i]);
                res.push_back(string(ch.begin(),ch.end()));
            }
        }
        return res;
    }
    vector<string> letterCasePermutation(string s) {
        dfs(0,s.length(),s);
        // return bfs(s);
        return res;
    }
};