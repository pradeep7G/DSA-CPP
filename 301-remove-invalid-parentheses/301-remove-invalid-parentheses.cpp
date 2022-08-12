class Solution {
public:
    void dfsPractice(int ind,int n,string &s,string validString,unordered_set<string> &res,int rmL,int rmR,int open){
        if(open<0 || rmL<0 || rmR<0)
             return ;
        if(ind==n){
            //reached end of the array
            if(open==0 && rmL==0 && rmR==0){
                res.insert(validString);
            }
            return ;
        }
        if(s[ind]=='('){
            //not use
            dfsPractice(ind+1,n,s,validString,res,rmL-1,rmR,open);
            //use
            dfsPractice(ind+1,n,s,validString+"(",res,rmL,rmR,open+1);
        }
        else if(s[ind]==')'){
            //not use
            dfsPractice(ind+1,n,s,validString,res,rmL,rmR-1,open);
            // use
            dfsPractice(ind+1,n,s,validString+")",res,rmL,rmR,open-1);
        }
        else{
            dfsPractice(ind+1,n,s,validString+s[ind],res,rmL,rmR,open);
        }
    }
    vector<string> bfsPractice(string s){
        unordered_set<string> ht;
        queue<string> q;
        q.push(s);
        vector<string> res;
        while(q.size()){
            string str=q.front();
            q.pop();
            if(ht.count(str))
                continue;
            ht.insert(str);
            if(isValid(str)){
                res.push_back(str);
            }
            else{
                if(res.empty()){
                    for(int i=0;i<str.length();i++){
                        if(str[i]=='(' || str[i]==')'){
                            q.push(str.substr(0,i)+str.substr(i+1));
                        }
                    }
                }
            }
        }
        return res;
    }
    void solve(int ind,int n,string &s,string validString,unordered_set<string> &res,int rmL,int rmR,int open)
    {
        if(open<0 || rmL<0 || rmR<0)
            return ;
        if(ind==n){
            if(open==0 && rmL==0 && rmR==0){
                res.insert(validString);
            }
            return ;
        }
        if(s[ind]==')'){
            //not use
            solve(ind+1,n,s,validString,res,rmL,rmR-1,open);
            //use
            solve(ind+1,n,s,validString+")",res,rmL,rmR,open-1);
        }
        else if(s[ind]=='('){
            //not use
            solve(ind+1,n,s,validString,res,rmL-1,rmR,open);
            //use
            solve(ind+1,n,s,validString+"(",res,rmL,rmR,open+1);
        }
        else{
            solve(ind+1,n,s,validString+s[ind],res,rmL,rmR,open);
        }
    }
    vector<string> dfs(string s){
        int rmL=0,rmR=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                rmL++;
            }
            else if(s[i]==')'){
                if(rmL!=0){
                    rmL--;
                }
                else{
                    rmR++;
                }
            }
        }
        unordered_set<string> res;
        // solve(0,n,s,"",res,rmL,rmR,0);
        dfsPractice(0,n,s,"",res,rmL,rmR,0);
        return vector<string>(res.begin(),res.end());//remove duplicates
    }
    bool isValid(string &s){
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
            }
            else if(s[i]==')'){
                if(count==0){
                    return false;
                }
                else{
                    count--;
                }
            }
        }
        return count==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        //practice
        return dfs(s);
        return bfsPractice(s);
        //do bfs to generate valid paranthesis and once you find the solution then add them to the result
        //dfs ==> since unlike bfs we don't stop/know after removing parathesis which needs to be minimum so here first we found no.of excess brackets and then do bfs by removing/not removing and storing valid parenthesis;
        //finding excess left,right brackets
        
        //BFS
        unordered_set<string> ht;
        queue<string> q;
        q.push(s);
        vector<string> res;
        while(!q.empty()){
            string str=q.front();
            q.pop();
            if(ht.count(str))
                continue;
            ht.insert(str);
            if(isValid(str)){
                res.push_back(str);
            }
            else if(res.empty()){
                for(int i=0;i<str.size();i++){
                    if(str[i]==')' || str[i]=='('){
                        q.push(str.substr(0,i)+str.substr(i+1));
                    }
                }
            }
        }
        return res;
    }
};