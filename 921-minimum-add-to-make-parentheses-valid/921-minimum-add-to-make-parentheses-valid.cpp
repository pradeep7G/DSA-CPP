class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        stack<char> st;
        for(auto c:s){
            if(c=='(')
                st.push(c);
            else
            {
                if(st.empty() || st.top()!='('){
                    st.push(c);
                }
                else{
                    st.pop();
                }
            }
        }
        return st.size();
    }
};