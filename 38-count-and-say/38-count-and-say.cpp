class Solution {
public:
    string build(string str){
        int n=str.length();
        int i=0;
        string ret="";
        while(i<n){
            int j=i,count=1;
            while(j+1 <n && str[j]==str[j+1]){
                count++;
                j++;
            }
            j++;
            ret+=to_string(count)+str[i];
            i=j;
        }
        return ret;
    }
    string countAndSay(int n) {
        string ans="1";
        // if(n==1)
        //     return ans;
        // ans=countAndSay(n-1);
        // ans=build(ans);
        for(int i=1;i<n;i++){
            ans=build(ans);
        }
        return ans;
    }
};