class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n=s.length(),m=p.length();
        int matched=0;
        unordered_map<char,int> mp;
        for(auto c:p)mp[c]++;
        int left=0,right=0;
        for(;right<n;right++){
            char rightchar=s[right];
            if(mp.find(rightchar)!=mp.end()){
                mp[rightchar]--;
                if(mp[rightchar]==0)
                    matched++;
            }
            if(matched==mp.size()){
                res.push_back(left);
            }
            if(right>=m-1){
                char leftchar=s[left++];
                if(mp.find(leftchar)!=mp.end()){
                    if(mp[leftchar]==0){ //cause window can have redundant characters
                        matched--; 
                    }
                    mp[leftchar]++;
                }
            }
        }
        return res;
    }
};