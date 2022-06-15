class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[&](string a,string b){
           return a.length() < b.length();
        });
        unordered_map<string,int> dp;
        int ans=1;
        for(auto word:words){
            dp[word]=1;
            for(int i=0;i<word.size();i++){
                string prev=word.substr(0,i)+word.substr(i+1);
                if(dp.find(prev)!=dp.end()){
                    dp[word]=max(dp[word],1+dp[prev]);
                    ans=max(ans,dp[word]);
                }
            }
        }
        return ans;
    }
    
};