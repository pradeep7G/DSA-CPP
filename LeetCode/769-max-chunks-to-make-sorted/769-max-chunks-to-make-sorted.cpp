class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt=0;
        vector<int> sortedArr(arr);
        sort(begin(arr),end(arr));
        int sum=0,sortSum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            sortSum+=sortedArr[i];
            if(sum==sortSum)
                cnt++;
        }
        return cnt;
    }
};