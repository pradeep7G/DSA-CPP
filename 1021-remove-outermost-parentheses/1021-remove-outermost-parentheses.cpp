class Solution {
public:
    string removeOuterParentheses(string s) {
        int start=0,cnt=0;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')'){
                cnt--;
                if(cnt==0){
                    ans+=s.substr(start+1,i-start-1);
                    start=i+1;
                }
            }
        }
        return ans;
    }
};