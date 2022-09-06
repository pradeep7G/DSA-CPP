class Solution {
public:
    typedef long long ll;
    int MOD=1e9+7;
    int solve(int i,int start, int end,int k,vector<unordered_map<int,int>> &dp){
        //early termination
        if(start<end){
            if((start+(k-i)) < end)
                return 0;
        }
        else if(start>end){
            if((start - (k-i))> end )
                return 0;
        }
        if(i>k)
            return 0;
        if(i==k){
            if(start!=end)
             return 0;
            else if(start==end)
             return 1;
        }
        if(dp[i].count(start)){
            return dp[i][start] % MOD;
        }
        return dp[i][start]=((ll)solve(i+1,start+1,end,k,dp)+(ll)solve(i+1,start-1,end,k,dp))%MOD;
    }
    int nCr(int k,int r){
        if(r==0)
            return 1;
        vector<int> v(r+1,0);
        v[0]=1;
        for(int i=1;i<=k;i++){
            for(int j=r;j>0;j--){
                v[j]=((v[j]%MOD) + (v[j-1]%MOD))%MOD;
            }
        }
        return v[r];
    }
    int approach2(int start,int end,int k){
        //two equations 1) l+r = k 2) r-l = diff. l = no.of left steps, r = no.of right steps
        // so solving two eq's l=(diff-k)/2,r=(diff+k)/2;
        //so basically our answer in of type l,r steps where l+r =k and so no.of possible permutations will be k!/(l! * r!) ==> k!/(r! * (k-r)!) ==> which is K choose R
        //Trivia: C(n,r) = C(n-1,r-1) + C(n-1,r)
        int diff=abs(start-end);
        if(diff>k || (diff+k)&1)
            return 0;
        long r=(diff+k)/2;
        return nCr(k,r);
    }
    int numberOfWays(int startPos, int endPos, int k) {
        return approach2(startPos,endPos,k);
        vector<unordered_map<int,int>> dp(k+1);
        return solve(0,startPos,endPos,k,dp);
    }
};