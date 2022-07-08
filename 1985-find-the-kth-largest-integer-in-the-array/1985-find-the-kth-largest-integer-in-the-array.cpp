class Solution {
public:
    int MOD=1e9+7;
    struct compare {
        bool operator()(string &a,string &b){
            if(a.length()==b.length()){
                return a>b;
            }
            return a.length()>b.length();
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        //NlogN
        // sort(begin(nums),end(nums),[&](string &a,string &b){
        //    if(a.length()==b.length())
        //        return a>b;
        //    return a.length()>b.length();
        // });
        priority_queue<string,vector<string>,compare> pq;
        for(auto i:nums)
        {
            pq.push(i);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};