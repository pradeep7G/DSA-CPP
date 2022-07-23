class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        //3*n elements a-b  min so a as min as possible b as max as possible
        //0...n-1,n...2n-1,2n,...3n-1,3n
        //we select n min elements upto 2n same in reverse n max elements up to n
        //and select min value
        int N=nums.size();
        int n=N/3;
        vector<long long>smallest(n+1),largest(n+1);
        priority_queue<pair<long long,int>> maxHeap;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> minHeap;
        long long sumN=0;
        for(int i=0;i<n-1;i++){
            sumN+=nums[i];
            maxHeap.push({nums[i],i});
        }
        for(int i=n-1;i<2*n;i++){
            maxHeap.push({nums[i],i});
            sumN+=nums[i];
            while(maxHeap.size()>n && maxHeap.top().first >= nums[i]){
                auto top=maxHeap.top();
                maxHeap.pop();
                sumN-=top.first;
            }
            if(maxHeap.size()==n)
            smallest[i-n+1]=sumN;
            // else
            // smallest[i-n+1]=smallest[i-n];
        }
        sumN=0;
        for(int i=3*n-1;i>2*n;i--){
            sumN+=nums[i];
            minHeap.push({nums[i],i});
        }
        for(int i=2*n;i>=n;i--){
            minHeap.push({nums[i],i});
            sumN+=nums[i];
            while(minHeap.size()>n && minHeap.top().first <= nums[i]){
                auto top=minHeap.top();
                minHeap.pop();
                sumN-=top.first;
            }
            if(minHeap.size()==n)
            largest[i-n]=sumN;
            // else
            // largest[i-n]=largest[i-n+1];
        }
        long long ans=1e18;
        for(int i=0;i<=n;i++){
            ans=min(ans,smallest[i]-largest[i]);
        }
       
        return ans;
    }
};