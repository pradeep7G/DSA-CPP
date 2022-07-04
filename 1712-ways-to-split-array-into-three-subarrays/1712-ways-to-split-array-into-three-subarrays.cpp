class Solution {
public:
    int MOD=1e9+7;
    int waysToSplit(vector<int>& nums) {
        //presums --> pre[i]<=pre[j]<=pre[k] (0,i)<=(i,j)<=(j,k); //i = left_boundary, j=right_boundary
        
        //left sum --  i_middle sum_j -- right sum
        //we are searching for smallest point that satisfies condition and the largest point that satisfies the condition, so if we find the largest that means we can remove an element from middle sum and add it to the right sum and we can do this until smallest possible i constraint, so we add j-i to the result, that's how we are optimizing/pruning the search by calculating smallest and largest possiblities of left boundary satisfying the predicate
        int n=nums.size();
        vector<int> pre(n,0);
        partial_sum(nums.begin(),nums.end(),pre.begin());
        long long res=0;
        for(int i=0;i<n-2;i++){
           //2*prefix[i]<=pref[j] and pre[j]<=(pref[i]+pref[n])/2
            auto smallest_left=lower_bound(pre.begin()+i+1,pre.end()-1,2*pre[i]);//left most possible boundary
            auto largest_left=upper_bound(smallest_left,pre.end()-1,(pre[i]+pre[n-1])/2);//right most boundary
            // cout<<i<<" "<<smallest_left<<" "<<largest_left<<"\n";
            res+=(largest_left-smallest_left)%MOD;
        }
        return res%MOD;
    }
};