class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans="";
        for(int i=0;i<strs[0].size();i++)
        {
           bool flag=true;
           for(int j=1;j<strs.size();j++){
               if(i<strs[j].length() && strs[j][i]!=strs[0][i]){
                   flag=false;
                   break;
               }
               else if(i>=strs[j].length()){
                   return ans;
               }
           }
            if(flag)
                ans+=strs[0][i];
            else
                break;
        }
        return ans;
    }
};