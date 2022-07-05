class Solution {
public:
    string frequencySort(string s) {
        string res="";
        unordered_map<char,int> freq;
        for(auto c:s)
            freq[c]++;
        priority_queue<pair<int,char>> pq;
        for(auto char_freq:freq){
            pq.push({char_freq.second,char_freq.first});
        }
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int count=top.first;
            int c=top.second;
            for(int i=0;i<count;i++)
                res.push_back(c);
        }
        return res;
    }
};