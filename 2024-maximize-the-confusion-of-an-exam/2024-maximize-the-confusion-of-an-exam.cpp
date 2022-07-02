class Solution {
public:
    int singlepass(string ans,int k){
        int count_t=0,count_f=0,res=0;
        int left=0;
        for(int right=0;right<ans.length();right++){
            if(ans[right]=='T')
                count_t++;
            else
                count_f++;
            while(min(count_t,count_f)>k){
                if(ans[left++]=='T')
                    count_t--;
                else
                    count_f--;
            }
            res=max(res,right-left+1);
        }
        return res;
    }
    int maxConsecutiveAnswers(string ans, int k) {
        return singlepass(ans,k);
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