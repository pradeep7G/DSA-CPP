class Solution {
public:
    int solve(string word){
        int n=word.length();
        int count=1,len=1,res=0;
        for(int i=1;i<n;i++){
            if(word[i-1]==word[i]){
                len++;
            }
            else if(word[i-1]<word[i]){
                count++;
                len++;
            }
            else{
                len=1;
                count=1;
            }
            if(count==5){
                res=max(res,len);
            }
        }
        return res;
    }
    int longestBeautifulSubstring(string word) {
        return solve(word);
        int n=word.length();
        int cnt=1,len=1,res=0;
        for(int i=1;i<n;i++){
            if(word[i-1]==word[i])
            {
                len++;
            }
            else if(word[i-1]<word[i]){
                cnt++;
                len++;
            }
            else{
                len=1;
                cnt=1;
            }
            if(cnt==5){
                res=max(res,len);
            }
        }
        return res;
    }
};