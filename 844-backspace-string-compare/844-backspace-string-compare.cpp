class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        for(auto i:s){
            if(i=='#'){
                if(!s1.empty()){
                    s1.pop();
                }
            }
            else{
                s1.push(i);
            }
        }
        for(auto i:t){
            if(i=='#'){
                if(!s2.empty()){
                    s2.pop();
                }
            }
            else{
                s2.push(i);
            }
        }
        while(!s1.empty() && !s2.empty()){
            if(s1.top()!=s2.top()){
                return false;
            }
            else{
                s1.pop();
                s2.pop();
            }
        }
        if(!s1.empty() || !s2.empty()){
            return false;
        }
        return true;
    }
};