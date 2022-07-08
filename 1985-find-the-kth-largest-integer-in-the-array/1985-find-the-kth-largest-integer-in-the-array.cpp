class Solution {
public:
    int MOD=1e9+7;
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(begin(nums),end(nums),[&](string &a,string &b){
           if(a.length()==b.length())
               return a>b;
           return a.length()>b.length();
        });
        
        return nums[k-1];
    }
};