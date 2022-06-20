class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int ans=0,cnt=0;
        for(auto c:s){
            if(c=='('){
                cnt++;
            }
            else if(c==')'){
                cnt--;
            }
            if(cnt > ans){
                ans=cnt;
            }
        }
        return ans;
    }
};