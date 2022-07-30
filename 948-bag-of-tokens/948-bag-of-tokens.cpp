class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size(),p=power;
        int i=0,j=n-1;
        int count=0,maxAnswer=0;
        for(;i<=j;){
            if(p>=tokens[i]){
                count++;
                p-=tokens[i++];
            }
            else if(count>0){
                p+=tokens[j--];
                count--;
            }
            else{
                return maxAnswer;
            }
            maxAnswer=max(maxAnswer,count);
        }
        return maxAnswer;
    }
};