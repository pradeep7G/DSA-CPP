class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        s.push(pushed[0]);
        int i=1,j=0;
        while(i<pushed.size() && j<popped.size()){
            if(!s.empty() && s.top() == popped[j]){
                while(!s.empty() && j<pushed.size() && s.top()==popped[j]){
                    s.pop();
                    j++;
                }
            }
            s.push(pushed[i]);
            i++;
        }
         while(!s.empty() && j<pushed.size() && s.top()==popped[j]){
                    s.pop();
                    j++;
                }
        return s.empty();
    }
};