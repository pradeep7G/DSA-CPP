class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        int n=s.length();
        res.push_back(s);
        for(int i=0;i<n;i++){
            if(!isalpha(s[i]))
                continue;
            int size=res.size();
            for(int j=0;j<size;j++){
                vector<char> chs(res[j].begin(),res[j].end());
                if(isupper(chs[i]))
                    chs[i]=tolower(chs[i]);
                else
                    chs[i]=toupper(chs[i]);
                res.push_back(string(chs.begin(),chs.end()));
            }
        }
        return res;
    }
};