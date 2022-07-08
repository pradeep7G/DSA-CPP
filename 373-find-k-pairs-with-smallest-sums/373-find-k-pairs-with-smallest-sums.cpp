class Solution {
public:
    typedef pair<int,pair<int,int>> triplet;
    vector<vector<int>> AC_BUT_MLE(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<vector<int>> res;
        priority_queue<triplet,vector<triplet>,greater<triplet>> pq;
        int i=0,j=0;
        vector<vector<int>> vis(nums1.size(),vector<int>(nums2.size(),false));
        pq.push({nums1[i]+nums2[j],{i,j}});
        int count=k;
        vis[0][0]=true;
        while(count-- && !pq.empty()){
            if(pq.size()>=2*k)
                break;
            auto top=pq.top();
            pq.pop();
            auto sum=top.first;
            int x=top.second.first,y=top.second.second;
            res.push_back({nums1[x],nums2[y]});
            if(x+1<nums1.size() && !vis[x+1][y]){;
                pq.push({nums1[x+1]+nums2[y],{x+1,y}});
                vis[x+1][y]=true;                                            
            }
            if(y+1<nums2.size() && !vis[x][y+1]){
                pq.push({nums1[x]+nums2[y+1],{x,y+1}});
                vis[x][y+1]=true;
            }
        }
        for(;res.size()<k && !pq.empty();){
            auto top=pq.top();
            pq.pop();
            res.push_back({nums1[top.second.first],nums2[top.second.second]});
        }
        return res;
    }
    struct compare {
        bool operator()(triplet &a,triplet &b){
            return a.first > b.first;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //bubbling out , similar to marging k sorted lists, we try with nums1[0 ... n-1] + nums2[0], we take the smallest one and increase the index (i.e in merge-k-sorted we increase column) here we increse index of nums2 index; this method avoids MEMORY LIMIT EXCEEDS ERROR as we are pushing only one element at a time into the priority_queue
        //Time Complexity: O(KLOGK),O(K)
        vector<vector<int>> k_smallest_pairs;
        priority_queue<triplet,vector<triplet>,compare> pq; //max_heap to get k smallest
        int m=nums1.size(),n=nums2.size();
        if(n==0 || m==0)
            return k_smallest_pairs;
        for(int i=0;i<m;i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        while(k-->0 && !pq.empty()){
            auto top=pq.top();
            pq.pop();
            int i=top.second.first,j=top.second.second;
            k_smallest_pairs.push_back({nums1[i],nums2[j]});
            if(j+1==n)
                continue;
            pq.push({nums1[i]+nums2[j+1],{i,j+1}});
        }
        return k_smallest_pairs;
    }
};