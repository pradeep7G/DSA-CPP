class Solution {
public:
    string minRemoveToMakeValid(string st) {
        stack<int> s;
        for(int i=0;i<st.size();i++){
            if(st[i]==')'){
                if(!s.empty()){
                    if(st[s.top()]=='('){
                        s.pop();
                    }
                    else{
                        s.push(i);
                    }
                }
                else{
                    s.push(i);
                }
            }
            else if(st[i]=='('){
                s.push(i);
            }
        }
        unordered_map<int,int> mp;
        while(!s.empty()){
            mp[s.top()]=1;
            s.pop();
        }
        string ans="";
        for(int i=0;i<st.length();i++){
            if(!mp[i]){
                ans+=st[i];
            }
        }
        return ans;
    }
};