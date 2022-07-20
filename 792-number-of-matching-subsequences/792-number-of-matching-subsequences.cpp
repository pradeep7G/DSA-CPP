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
    int bruteFroce(string s,vector<string> &words){
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
    //TC:O(words.length * words[i].length * log(s.length())) O(50 * 5000 * log(50000))
    //SC: O(26)
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> ch[26];
        int count=0;
        for(int i=0;i<s.length();i++){
            ch[s[i]-'a'].push_back(i);
        }
        for(auto w:words){
            bool flag=true;
            int pos=-1;
            for(auto c:w){
                auto ind=upper_bound(ch[c-'a'].begin(),ch[c-'a'].end(),pos);
                if(ind==ch[c-'a'].end())
                {
                    flag=false;
                    break;
                }
                pos=*ind;
            }
            if(flag)
                count++;
        }
        return count;
    }
};