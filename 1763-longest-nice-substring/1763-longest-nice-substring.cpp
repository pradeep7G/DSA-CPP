class Solution {
public:
    string longestNiceSubstring(string str) {
        unordered_set<char> s; //if for a letter that doesn't have it's counterpart then it can't be present in the answer..?!!! so we divide left and right of that letter..? riging bells?? divide and conquer.....!!!!
        for(auto c:str)
            s.insert(c);
        int n=str.length();
        for(int i=0;i<n;i++){
            if(s.count(tolower(str[i])) && s.count(toupper(str[i])))
                continue;
            string left=longestNiceSubstring(str.substr(0,i));
            string right=longestNiceSubstring(str.substr(i+1));
            return (left.length()>=right.length())?left:right;
        }
        return str; 
    }
};