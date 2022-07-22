class Solution {
public:
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
    vector<string> removeInvalidParentheses(string s) {
        //do bfs to generate valid paranthesis and once you find the solution then add them to the result
        //dfs ==> since unlike bfs we don't stop/know after removing parathesis which needs to be minimum so here first we found no.of excess brackets and then do bfs by removing/not removing and storing valid parenthesis;
        //finding excess left,right brackets
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
        solve(0,n,s,"",res,rmL,rmR,0);
        return vector<string>(res.begin(),res.end());//remove duplicates
    }
};