class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;//follows inbuilt hashing when adding elements to it!!
        vector<string> res;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(i+10>n)
                break;
            string str=s.substr(i,10);
            if(mp.count(str)){
                if(mp[str]==1)
                    res.push_back(str);
            }
            mp[str]++;
        }
        return res;
    }
};