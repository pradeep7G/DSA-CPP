class Solution {
public:
    map<long,long,greater<>> mp;
    bool isValid(int mid,int k){
        for(auto &[n,cnt]:mp){
            if(n<=mid)
                break;
            k-=(long)(cnt) * (long)(n-mid);
            if(k<=0)
                return true;
        }
        return k<=0;
    }
    int practice(vector<int> &inventory,int orders){
        int n=inventory.size();
        int k=orders;
        for(int i=0;i<n;i++)
            mp[inventory[i]]++;
        long res=0,lo=0,hi=*max_element(begin(inventory),end(inventory)),mod=1e9+7;
        long lvl=-1;
        while(lo<=hi){
            long mid=lo+(hi-lo)/2;
            if(isValid(mid,k)){
                lvl=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        lvl++;
        for(auto &[val,cnt]:mp){
            if(val<=lvl)
                break;
            k-=(long)(cnt*(val-lvl));
            res=(res+(((long)((val * (val+1))/2) - ((long)(lvl * (lvl+1))/2)) % mod * cnt % mod));
            // res=(res+(long)(((((val*(val+1))/2) - ((lvl * (lvl-1))/2))%mod * cnt%mod)))%mod;
        }
        if(k)
            res=(res %mod+(k*(lvl)) %mod)%mod;
        return res;
    }
    // bool isValid(int val,int k){
    //     for(auto &[n,cnt]:mp){
    //         if(n<=val)
    //             break;
    //         k-=(long)cnt*(n-val);
    //         if(k<=0)
    //             return true;
    //     }
    //     return k<=0;
    // }
    //  bool isValidPractice(map<int,int,greater<>> &mp,int val,int k){
    //     for(auto &[n,cnt]:mp){
    //         if(n<=val)
    //             break;
    //         k-=(long)cnt*(n-val);
    //         if(k<=0)
    //             return true;
    //     }
    //     return k<=0;
    // }
    // int binarySearch(vector<int> &inventory,int order){
    //     int n=inventory.size();
    //     int K=order;
    //     for(int i=0;i<n;i++)
    //         mp[inventory[i]]++;
    //     long ans=0,mod=1e9+7,lo=0,hi=*max_element(begin(inventory),end(inventory));
    //     while(lo<=hi){
    //         long mid=lo+(hi-lo)/2;
    //         if(isValid(mid,K)){
    //             lo=mid+1;
    //         }
    //         else
    //             hi=mid-1;
    //     }
    //     for(auto &[n,cnt]:mp){
    //         if(n<=lo)
    //             break;
    //         K-=(cnt)*(n-lo);
    //         ans=(ans+(n+lo+1)*(n-lo)/2 % mod * cnt % mod)%mod;
    //     }
    //     if(K)
    //         ans=(ans+lo*K %mod)%mod;
    //     return ans;
    // }
    //greedy method, we take balls/orders greedily until we exhaust orders or balls, 
    //we take max balls by comparing next unique freq of balls let's say we have 4,5,5 ==> here we can greedily take balls from 5,5 till become 4,4,4 ==> then if current state if 3,4,4,4 ==> again we can greedly take until 3,3,3,3 ==> but we need to have another pointer i so that we can track the the cur and next,values of the balls and if current orders are less than we need to carefully pick the required no.of balls let's say if we need 3 balls but the current state is 1,4,4,4,4 ==> then we can't pick till 1,1,1,1,1 ==> if we pick (i*h) balls they are more than required so we pick only (k%i) balls after picking up (k/i) balls i.e if the state is 1,3,3 and i need 3 balls ==> i can do this like pick till 1,2,2 (k/i) ==> then need 1 balls so pick (k%i)
    int greedy(vector<int> &balls,int order){
        sort(rbegin(balls),rend(balls));//sorting descending
        int i=0;
        long ans=0,mod=1e9+7,n=balls.size(),k=order,cur=balls[0];
        while(k){
            while(i<n && balls[i]==cur)i++;
            long next=i==n?0:balls[i],h=cur-next,r=0,cnt=min(k,i*h);
            if(k< i*h){
                h= k/i;
                r= k%i;
            }
            long val=cur-h;
            ans=(ans+(cur+val+1)*h/2 *i + r*val)%mod;
            k-=cnt;
            cur=next;
        }
        return ans;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        //10,9,9,7,7,6,6 orders are 9,9,9,7,7,6,6 and ==> ==> 7,7,7,7,7,6,6 , 10*x + 9*y + 8*z + .. till orders exhaust
        //can do binary search O(N*Log(max(A))) or sort and greedy method by comparing cur and next;
        // return binarySearchPractice(inventory,orders);
        return practice(inventory,orders);
        // return greedyPractice(inventory,orders);
        // return greedy(inventory,orders);
        // return binarySearch(inventory,orders);
    }
    // int binarySearchPractice(vector<int> &inventory,int orders){
    //     map<int,int,greater<>> item_freq;
    //     int max_element=0;
    //     for(auto i:inventory){
    //         max_element=max(max_element,i);
    //         item_freq[i]++;
    //     }
    //     int n=inventory.size(),k=orders;
    //     long long ans=0,mod=1e9+7,lo=0,hi=max_element;
    //     while(lo<=hi){
    //         int mid=lo+(hi-lo)/2;
    //         if(isValidPractice(item_freq,mid,orders)){
    //             lo=mid+1;
    //         }
    //         else{
    //             hi=mid-1;
    //         }
    //     }
    //     for(auto &[val,cnt]:item_freq){
    //         if(val<=lo){
    //             break;
    //         }
    //         k-=(cnt*(val-lo));
    //         ans=(ans+(val+lo+1)*(val-lo)/2 %mod * cnt%mod)%mod;
    //     }
    //     if(k){
    //         ans=(ans+(lo*k)%mod)%mod;
    //     }
    //     return ans;
    // }
    // int greedyPractice(vector<int> &balls,int orders){
    //     int n=balls.size();
    //     long long k=orders;
    //     sort(rbegin(balls),rend(balls));//sort in decreasing
    //     int i=0;
    //     long long ans=0,mod=1e9+7,cur=balls[0];
    //     while(k){
    //         while(i<n && balls[i]==cur)
    //             i++;
    //         long long next=(i==n ? 0:balls[i]),diff=cur-next,r=0,cnt=min(k,(long long)i*diff);
    //         if(k< i*diff){
    //             //then we can take the required balls and return solution but we need to carefully pick from available set of balls
    //             diff=(k/i);
    //             r=(k%i);
    //         }
    //         long long val=cur-diff;
    //         ans=(ans+(cur+val+1)* diff/2 * i + r*val)%mod;
    //         k-=cnt;
    //         cur=next;
    //     }
    //     return ans;
    // }
};