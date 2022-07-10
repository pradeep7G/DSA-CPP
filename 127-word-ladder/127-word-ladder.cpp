class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(begin(wordList),end(wordList));
        queue<string> q;
        unordered_set<string> vis;
        if(st.find(endWord)==vis.end())
            return 0;
        q.push(beginWord);
        vis.insert(beginWord);
        int distance=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string word=q.front();
                q.pop();
                if(word==endWord)
                    return distance;
                for(int ind=0;ind<word.length();ind++){
                    for(char ch='a';ch<='z';ch++){
                        string tmp_word=word;
                        tmp_word[ind]=ch;
                        if(st.find(tmp_word)!=st.end())
                        {
                            if(vis.find(tmp_word)==vis.end())
                            {
                                q.push(tmp_word);
                                vis.insert(tmp_word);
                            }
                        }
                    }
                }
            }
            distance++;
        }
        return 0;
    }
};