class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,res=0;
        set<char> se;
        se.insert('a');
        se.insert('e');  
        se.insert('i');
        se.insert('o');  
        se.insert('u');
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            if(i<k-1)
            {
                if(se.count(s[i]))
                    count++;
                continue;
            }
            if(se.count(s[i]))
                    count++;
            res=max(res,count);
            count-=(se.count(s[i-k+1]));
        }
        return res;
    }
};