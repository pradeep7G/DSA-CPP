class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> good(begin(words),end(words));
        for(string s:words){
            for(int i=1;i<s.length();i++){
                good.erase(s.substr(i));
            }
        }
        int ans=0;
        for(string s:good){
            ans+=s.length()+1;
        }
        return ans;
    }
};