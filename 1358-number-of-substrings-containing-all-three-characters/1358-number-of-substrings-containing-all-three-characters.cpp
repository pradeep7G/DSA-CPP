class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0,n=s.length(),left=0,right=0;
        unordered_map<char,int> mp;
        vector<int> v;
        for(;right<n;right++){
            char rightchar=s[right];
            mp[rightchar]++;
            while(mp.size()==3){
                v.push_back(right);
                char leftchar=s[left++];
                mp[leftchar]--;
                if(mp[leftchar]==0)
                    mp.erase(leftchar);
            }
        }
        for(auto i:v)
            ans+=(n-i);
        return ans;
    }
};