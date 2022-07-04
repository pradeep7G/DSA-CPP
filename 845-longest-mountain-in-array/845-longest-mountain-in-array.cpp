class Solution {
public:
    int longestMountain(vector<int>& arr) {
      //calculate longest increasing subarray ending at i, do it from start and from end, finally take the optimal value. Multipass, O(N) time and O(N) space;
      // but can we have O(N) time and O(1) space; , just go on and count increasing and decreasing contigious arrays in single pass
        
        int res=0;
        int up=0,down=0;
        int n=arr.size();
        int i=1;
        while(i<n){
            while(i<n && arr[i-1]==arr[i])
                i++;
            up=0;
            while(i<n && arr[i-1]<arr[i])
               up++,i++;
            down=0;
            while(i<n && arr[i-1]>arr[i])
                down++,i++;
            if(up && down)
                res=max(res,up+down+1);
        }
        return res;
    
    }
};