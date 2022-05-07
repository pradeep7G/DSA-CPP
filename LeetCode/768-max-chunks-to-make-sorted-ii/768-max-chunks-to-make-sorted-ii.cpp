class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        long int sum=0,sortSum=0,ans=0;
        vector<int> sortedArr(arr);
        sort(begin(arr),end(arr));
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            sortSum+=sortedArr[i];
            if(sum==sortSum)ans++;
        }
        return static_cast<int>(ans);
    }
};