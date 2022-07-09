class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size=arr.size();
        unordered_map<int,int> mp;
        for(auto i:arr)
            mp[i]++;
        vector<int> res;
        for(auto i:mp)
            res.push_back(i.second);
        sort(begin(res),end(res));
        reverse(begin(res),end(res));
        int sum=0;
        for(int i=0;i<res.size();i++){
            sum+=res[i];
            if(sum>=(size/2))
                return i+1;
        }
        return res.size();
    }
};