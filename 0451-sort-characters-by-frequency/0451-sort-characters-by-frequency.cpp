class Solution {
public:
    string solve1(string &s){
        unordered_map<char,int> mp;
        for(auto c:s)
            mp[c]++;
        vector<char> v;
        for(auto c:s)
            v.push_back(c);
        sort(begin(v),end(v),[&](char &a,char &b){
           if(mp[a]==mp[b])
               return a<b;
           return mp[a]>mp[b]; 
        });
        string res="";
        for(auto c:v)
            res+=c;
        return res;
    }
    string solve2(string s){
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
            char ch=top.second;
            res+=string(count,ch);//std:string(count,char) : string(3,'a') == "aaa"
        }
        return res;
    }
    string frequencySort(string s) {
        return solve1(s);
        return solve2(s);
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
            int ch=top.second;
            res+=string(count,ch); //std::string(count,char)
        }
        return res;
    }
};