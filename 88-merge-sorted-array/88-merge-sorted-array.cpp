class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1;
        int counter=m+n-1;
        while(i>=0 && j>=0 && counter>=0){
            if(nums1[i]>nums2[j]){
                swap(nums1[i--],nums1[counter--]);
            }
            else if(nums1[i]<nums2[j]){
               nums1[counter--]=nums2[j--];
            }
            else{
                nums1[counter--]=nums2[j--];
            }
        }
        
        while(i>=0 && counter>=0){
            nums1[counter--]=nums1[i--];
        }
        while(j>=0 && counter>=0){
            nums1[counter--]=nums2[j--];
        }
        
    }
};