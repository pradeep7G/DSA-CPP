class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(),m=t.length();
        unordered_map<char,int> mp;
        for(auto c:t)
            mp[c]++;
        int left=0,right=0;
        int matched=0;
        string ret="";int minlen=INT_MAX,index=-1;
        for(;right<n;right++){
            char rightchar=s[right];
            if(mp.find(rightchar)!=mp.end()){
                mp[rightchar]--;
                if(mp[rightchar]>=0)
                    matched++;
            }
            while(matched==m){
                //shrink
                if(minlen > right-left+1){
                    index=left;
                    minlen=right-left+1;
                }
                char leftchar=s[left++];
                if(mp.find(leftchar)!=mp.end()){
                    if(mp[leftchar]==0){
                        matched--;
                    }
                    mp[leftchar]++;
                }
            }
        }
        if(minlen==INT_MAX || index==-1)
             return "";
        return s.substr(index,minlen);
    }
};