class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        //wow, this xor trick seems super interesting
        
        /*
            int allxor=0;
            for(int i=1;i<=nums.size();i++)
                allxor^=i;
            int num_xor=accumulate(begin(nums),end(nums),0,[&](int x,int y){
                return x^y;
            });
            return num_xor ^ allxor;
        */
        
        //can you do it with cyclic sort?
        int i=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]<n && nums[i]!=nums[nums[i]]){
                swap(nums[i],nums[nums[i]]);
            }
            else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i)
                return i;
        }
        return n;
    }
};