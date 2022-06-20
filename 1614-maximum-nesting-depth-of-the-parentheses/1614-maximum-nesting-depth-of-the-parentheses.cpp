class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int ans=0;
        for(auto c:s){
            if(c=='('){
                st.push(c);
            }
            else if(c==')'){
                st.pop();
            }
            if(st.size() > ans){
                ans=st.size();
            }
        }
        return ans;
    }
};