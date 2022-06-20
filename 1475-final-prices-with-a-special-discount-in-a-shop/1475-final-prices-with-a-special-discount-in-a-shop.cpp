class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return {};
        vector<int> res(n);
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;i++){
            while(!s.empty() && prices[i]<=prices[s.top()]){
                res[s.top()]=prices[s.top()]-prices[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            res[s.top()]=prices[s.top()];
            s.pop();
        }
        return res;
    }
};