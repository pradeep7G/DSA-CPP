class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans=0;
        while(1){
            sort(begin(amount),end(amount));
            int mn=1,mx=2;      
            if(amount[mn]<=0 && amount[mx]<=0)
                break;
            ans++;
//             if(mn==mx)
//             {   
                
//                 amount[mn]--;continue;
//             }
            if(amount[mn]>0)
            amount[mn]--;
            if(amount[mx]>0)
            amount[mx]--;
        }
        return ans;
    }
};