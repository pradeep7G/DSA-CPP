class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
        int trues=0;
        int left=0,right=0,n=ans.length();
        int res=0;
        for(;right<n;right++){
            if(ans[right]=='T')
                trues++;
            while(right-left+1-trues>k){
                trues-=(ans[left++]=='T');
            }
            res=max(res,right-left+1);
        }
        left=0,right=0;
        trues=0;
        for(;right<n;right++){
            if(ans[right]=='F')
                trues++;
            while(right-left+1-trues>k){
                trues-=(ans[left++]=='F');
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};