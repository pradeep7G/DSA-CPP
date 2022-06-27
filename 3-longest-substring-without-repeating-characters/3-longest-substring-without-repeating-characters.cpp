class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n=s.length();
        if(n==0)
            return 0;
        int ans=0;
        int left=0,right=0;
        for(;right<n;right++){
            int rightchar=s[right];
            if(mp.find(rightchar)!=mp.end()){
                left=max(left,mp[rightchar]+1);
            }
            mp[rightchar]=right;
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};