class Solution {
public:
    int MX=2e5+5;
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> pref(MX,0);
        startPos++; //1 - n co-ordinate system,
        for(auto it:fruits){
            pref[it[0]+1]=it[1];
        }
        for(int i=1;i<MX;i++){
            pref[i]+=pref[i-1];
        }
        //Case1:moving right,first we move right and find the left most possible position and take all the fruits in that path,
        //Case2:moving left,first we move left and find the rightmost possible position and take all the fruits in that path
        int ans=0,i,l,r;
        for(r=startPos;r<MX && r<=startPos+k;r++){
            l=min(startPos,startPos-(k-2*(r-startPos)));
            l=max(1,l);
            ans=max(ans,pref[r]-pref[l-1]);
        }
        for(l=startPos;l>0 && l>=startPos-k;l--){
            r=max(startPos,startPos+(k-2*(startPos-l)));
            r=min(MX-1,r);
            ans=max(ans,pref[r]-pref[l-1]);
        }
        return ans;
    }
};