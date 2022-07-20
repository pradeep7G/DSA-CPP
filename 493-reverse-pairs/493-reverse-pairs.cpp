class Solution {
public:
    typedef long long ll;
    int merge(vector<int> &nums,int i,int j,int k){
        int pairs=0;
        int first=i,second=j+1;
        for(;first<=j && second<=k;){
            if((ll)nums[first]> (ll)2*(ll)nums[second]){
                pairs+=j-first+1;
                second++;
            }
            else{
                first++;
            }
        }
        vector<int> temp(k-i+1);
        first=i,second=j+1;int tmp=0;
        while(first<=j && second<=k){
            if(nums[first]<=nums[second]){
                temp[tmp++]=nums[first++];
            }
            else{
                temp[tmp++]=nums[second++];
            }
        }
        while(first<=j){
            temp[tmp++]=nums[first++];
        }
        while(second<=k){
            temp[tmp++]=nums[second++];
        }
        first=i,tmp=0;
        for(;first<=k;first++)
            nums[first]=temp[tmp++];
        return pairs;
    }
    int mergeSort(vector<int> &nums,int i,int j){
        int pairs=0;
        if(i<j){
            int mid=i+(j-i)/2;
            pairs+=mergeSort(nums,i,mid);
            pairs+=mergeSort(nums,mid+1,j);
            pairs+=merge(nums,i,mid,j);
        }
        return pairs;
    }
    int reversePairs(vector<int>& nums) {
        //first array is sorted and second array is sorted if for any element i in first the condition holds, then the condition holds for the rest of the elements also
        vector<int> find=nums;
        return mergeSort(find,0,nums.size()-1);
    }
};