class Solution {
public:
  void nextPerm(vector<int> &nums){
        int pivot=-1;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1])
                pivot=i;
        }
        if(pivot==-1){
            reverse(begin(nums),end(nums));
            return ;
        }
        int minSufIndex=-1;
        for(int i=pivot+1;i<n;i++){
            if(nums[i]>nums[pivot])
                minSufIndex=i;
        }
        swap(nums[minSufIndex],nums[pivot]);
        reverse(nums.begin()+pivot+1,nums.end());
        return ;
    }
    void solve(vector<int> &nums,vector<vector<int>> &res,int i,int n){
       
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        // solve(nums,res,0,n);
        // return res;
        
        //extra calculations for no.of permutatin possible with dups allowed, so that we can call next_permutation that many times;
        // unordered_map<int,int> mp;
        // vector<long long> fac(11,1);
        // for(long long i=1;i<=10;i++){
        //     fac[i]=i*fac[i-1];
        // }
        // long long uniquePerms=1;
        // for(int i=n;i>0;i--)
        //     uniquePerms*=i;
        // long long dupPerms=1;
        // for(auto i:nums)
        //     mp[i]++;
        // for(auto i:mp){
        //     if(i.second>1)
        //     {
        //         dupPerms*=fac[i.second];
        //     }
        // }
        // uniquePerms/=dupPerms;
        // res.emplace_back(nums);
        // uniquePerms--;
        
        //can avoided all possible permutations calculations, we just need to check how many times we can run the nextPermutation function, so we just compare the next permutation with initial state, if it reached initial state then we explored all the permutations
        vector<int> tmp=nums;
        res.push_back(tmp);
        while(true){
            nextPerm(nums);
            if(nums==tmp)
                break;
            res.emplace_back(nums);
        }
        return res;
    }
};