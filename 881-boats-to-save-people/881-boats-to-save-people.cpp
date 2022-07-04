class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(begin(people),end(people));
        int lo=0,hi=n-1;
        int res=0;
        while(lo<=hi){
            if(people[lo]+people[hi]<=limit){
                lo++;hi--;
                res++;
            }
            else
            {
                if(people[hi]<=limit)
                {
                  res+=1;   
                }
                hi--;
            }
        }
        return res;
    }
};