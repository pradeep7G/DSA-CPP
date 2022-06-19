class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        for(auto i:candyType)
            s.insert(i);
        return min(candyType.size()/2,s.size());
    }
};