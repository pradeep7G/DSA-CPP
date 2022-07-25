class Solution {
public:
    vector<string> ans;
    void dfs(int index,int n,string &digits,string &combination,unordered_map<char,string> &mp){
        if(index==n){
            ans.push_back(combination);
            return ;
        }
        for(auto c:mp[digits[index]]){
            combination.push_back(c);
            dfs(index+1,n,digits,combination,mp);
            combination.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return {};
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        ans.clear();
        string combo="";
        dfs(0,digits.length(),digits,combo,mp);
        return ans;
        queue<string> q;
        int n=digits.size();
        q.push("");
        for(int i=0;i<n;i++){
            int size=q.size();
            while(size--){
                auto front=q.front();
                q.pop();
                string str=mp[digits[i]];
                for(char &ch:str){
                    q.push(front+ch);
                }
            }
        }
        vector<string> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};