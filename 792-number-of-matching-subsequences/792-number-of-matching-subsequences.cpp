class Solution {
public:
    bool isSubsequence(string &s,string &w){
        int i=s.length(),j=w.length();
        for(;i>=0 && j>=0;){
            if(s[i]==w[j]){
                i--;j--;
            }
            else{
                i--;
            }
        }
        return j<0;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt=0;
        unordered_map<string,int> mp;
        
        for(int i=0;i<words.size();i++){
            if(words[i].length()>s.length())
                continue;
            if(mp.find(words[i])!=mp.end())
            {
                cnt+=mp[words[i]];continue;
            }
            if(isSubsequence(s,words[i])){
                mp[words[i]]=1;
                cnt++;
            }
            else{
                mp[words[i]]=0;
            }
        }
        return cnt;
    }
};