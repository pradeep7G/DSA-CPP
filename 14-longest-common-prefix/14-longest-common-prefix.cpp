class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans="";
        sort(begin(strs),end(strs));
        
        for(int i=0;i<strs[0].size();i++)
        {
            bool is=true;
             for(int j=0;j<strs.size();j++){
                if(i<strs[j].length() && strs[0][i]!=strs[j][i]){
                    is=false;break;
                }
                 else if(i>=strs[j].length()){
                     return ans;
                 }
            }
            if(is)
                ans+=strs[0][i];
            else
                break;
        }
        return ans;
    }
};