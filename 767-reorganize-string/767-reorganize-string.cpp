class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        unordered_map<char,int> freq;
        for(auto c:s)
            freq[c]++;
        priority_queue<pair<int,char>> pq;
        for(auto i:freq)
            pq.push({i.second,i.first});
        pair<int,char> previousEntry={-1,-1};
        string res="";
        //we greedily choose a char and add it to res, then delay it until we get next non-same character, after that we add previous char it to the pq, we do it until pq becomes empty if pq becomes empty we have a string with no two adjacent characters are same, but since we need to know if we can complete organize original to the required form, if we can't then we return "" else we return res;
        while(!pq.empty()){
            auto currentEntry=pq.top();
            pq.pop();
            if(previousEntry.first>0){
                pq.push(previousEntry);
            }
            res.push_back(currentEntry.second);
            currentEntry.first--;
            previousEntry=currentEntry;
        }
        return res.length()==n?res:"";
    }
};