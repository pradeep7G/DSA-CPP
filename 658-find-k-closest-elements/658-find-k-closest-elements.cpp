class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // x can be present the arr or not!!,                                                                                               - do binary search for find element that is closes to the x ,                                                                 - let's say 'i' is the index of the number closest to x, so we need to have k closest numbers to that x.                       - we can have a priority queue of size k and we search for the solutions in range [i-k,i+k], and get the k closest element                                                                                                                             - Time Complexity: O(LogN + KLogK), Space Complexity: O(K)
        int index=closest_integer(arr,x),n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int start=max(index-k,0);
        int end=min(index+k,n-1);
        for(int i=start;i<=end;i++){
            pq.push({abs(x-arr[i]),i});
        }
        vector<int> ans;
        int i=0;
        while(!pq.empty()){
            if(i==k)
                break;
            auto top=pq.top();
            pq.pop();
            ans.push_back(arr[top.second]);
            i++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    int closest_integer(vector<int> &arr,int x){
        // find index of closest element to x;
        int n=arr.size();
        if(arr[0]>=x)
            return 0;
        else if(arr[n-1]<=x)
            return n-1;
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==x)
                return mid;
            if(arr[mid]<x){
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        // if(lo>0)
        //     return lo-1;
        return lo;
    }
};