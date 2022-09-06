class Solution {
public:
    bool check(string &pattern,string &res){
        int n=pattern.size();
        for(int i=0;i<n;i++){
            if(pattern[i]=='I'){
               if(res[i]>res[i+1])
                   return false;
            }
            else if(pattern[i]=='D')
            {
             if(res[i]<res[i+1])
                return false;
            }
        }
        return true;
    }
    string optimal(string pattern){
        string stack,res;
        int n=pattern.length();
        for(int i=0;i<=n;i++){
           stack.push_back('1'+i);
           if(i==n || pattern[i]=='I'){
               while(!stack.empty()){
                   res.push_back(stack.back());
                   stack.pop_back();
               }
           }
        }
        return res;
    }
    string smallestNumber(string pattern) {
        return optimal(pattern);
        int n=pattern.size();
        string res="";
        for(int i=1;i<=n+1;i++){
            res+=to_string(i);
        }
        string mini=res;
        reverse(begin(mini),end(mini));
        do{
            bool ch=check(pattern,res);
            if(ch)
            {
                long long res_n=stoi(res);
                long long mini_n=stoi(mini);
                if(res_n<mini_n){
                    mini=res;
                }
            }
        }while(next_permutation(begin(res),end(res)));
        return mini;
    }
};