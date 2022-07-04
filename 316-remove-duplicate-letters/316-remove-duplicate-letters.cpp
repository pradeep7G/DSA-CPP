class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> check(26,0);
        string ans="";
        vector<int> last_pos(26,-1);
        int n=s.length();
        for(int i=0;i<n;i++)
            last_pos[s[i]-'a']=i;
        for(int i=0;i<n;i++){
            if(check[s[i]-'a'])
                continue;
            while(ans.length()>0 && ans.back()>s[i] && last_pos[ans.back()-'a']>i){
               check[ans.back()-'a']=0;
               ans.pop_back();
            }
            ans.push_back(s[i]);
            check[s[i]-'a']=1;
        }
        return ans;
    }
};