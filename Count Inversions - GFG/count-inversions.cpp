// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    typedef long long ll;
    // long long int merge(long long arr[],long long l,long long mid,long long r){
        // long long inv=0;
        
        // long long n1=mid-l+1,n2=r-mid;
        // long long a[n1],b[n2];
        
        // for(int i=0;i<n1;i++)
        // a[i]=arr[i+l];
        // for(int i=0;i<n2;i++)
        // b[i]=arr[i+mid+1];
        
        // long long i=0,j=0,k=l;
        // while(i<n1 && j<n2){
        //     if(a[i]<=b[j]){
        //         arr[k]=a[i];
        //         k++;i++;
        //     }
        //     else{
        //         arr[k]=b[j];
        //         inv+=n1-i;
        //         k++;j++;
        //     }
        // }
        // while(i<n1){
        //     arr[k++]=a[i++];
        // }
        // while(j<n2){
        //     arr[k++]=b[j++];
        // }
        // return inv;
    // }
    // long long int mergesort(long long a[],long long low,long long high){
    //     long long inv=0;
    //     if(low<high){
    //         long long mid=low+(high-low)/2;
    //         inv+=mergesort(a,low,mid);
    //         inv+=mergesort(a,mid+1,high);
    //         inv+=merge(a,low,mid,high);
    //     }
    //     return inv;
    // }
    ll merge(ll arr[],ll low,ll mid,ll high){
        ll inv=0;
        ll n1=mid-low+1,n2=high-mid;
        ll a[n1],b[n2];
        for(ll i=low;i<n1;i++)
        a[i]=arr[i+low];
        for(ll i=0;i<n2;i++)
        b[i]=arr[i+mid+1];
        ll i=0,j=0,k=low;
        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                arr[k++]=a[i++];
            }
            else{
                inv+=n1-i;
                arr[k++]=b[j++];
            }
        }
        while(i<n1){
            arr[k++]=a[i++];
        }
        while(j<n2){
            arr[k++]=b[j++];
        }
        return inv;
    }
    ll mergesort(ll a[],ll low,ll high){
        ll inv=0;
        if(low<high){
            ll mid=low+(high-low)/2;
            inv+=mergesort(a,low,mid);
            inv+=mergesort(a,mid+1,high);
            inv+=merge(a,low,mid,high);
        }
        return inv;
    }
    long long inversionCount(long long arr[], long long n)
    {
        return mergesort(arr,0,n-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends