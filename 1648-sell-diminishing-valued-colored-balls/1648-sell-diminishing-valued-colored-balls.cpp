class Solution {
public:
    map<int,int,greater<>> mp;
    bool isValid(int val,int k){
        for(auto &[n,cnt]:mp){
            if(n<=val)
                break;
            k-=(long)cnt*(n-val);
            if(k<=0)
                return true;
        }
        return k<=0;
    }
     bool isValidPractice(map<int,int,greater<>> &mp,int val,int k){
        for(auto &[n,cnt]:mp){
            if(n<=val)
                break;
            k-=(long)cnt*(n-val);
            if(k<=0)
                return true;
        }
        return k<=0;
    }
    int binarySearch(vector<int> &inventory,int order){
        int n=inventory.size();
        int K=order;
        for(int i=0;i<n;i++)
            mp[inventory[i]]++;
        long ans=0,mod=1e9+7,lo=0,hi=*max_element(begin(inventory),end(inventory));
        while(lo<=hi){
            long mid=lo+(hi-lo)/2;
            if(isValid(mid,K)){
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        for(auto &[n,cnt]:mp){
            if(n<=lo)
                break;
            K-=(cnt)*(n-lo);
            ans=(ans+(n+lo+1)*(n-lo)/2 % mod * cnt % mod)%mod;
        }
        if(K)
            ans=(ans+lo*K %mod)%mod;
        return ans;
    }
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
        return binarySearchPractice(inventory,orders);
        return greedy(inventory,orders);
        return binarySearch(inventory,orders);
    }
    int binarySearchPractice(vector<int> &inventory,int orders){
        map<int,int,greater<>> item_freq;
        int max_element=0;
        for(auto i:inventory){
            max_element=max(max_element,i);
            item_freq[i]++;
        }
        int n=inventory.size(),k=orders;
        long long ans=0,mod=1e9+7,lo=0,hi=max_element;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isValidPractice(item_freq,mid,orders)){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        for(auto &[val,cnt]:item_freq){
            if(val<=lo){
                break;
            }
            k-=(cnt*(val-lo));
            ans=(ans+(val+lo+1)*(val-lo)/2 %mod * cnt%mod)%mod;
        }
        if(k){
            ans=(ans+(lo*k)%mod)%mod;
        }
        return ans;
    }
};