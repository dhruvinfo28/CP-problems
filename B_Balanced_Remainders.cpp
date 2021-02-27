#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<":"<<x<<endl
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        int a;
        for(int i=0;i<n;i++){
            cin>>a; arr[i] = a%3;
        }
        int c0,c1,c2;
        c0=c1=c2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) c0++;
            else if(arr[i]==1) c1++;
            else c2++;
        }
        // dbg(c0);
        // dbg(c1);
        // dbg(c2);
        int count = n/3;
        // dbg(count);
        int ans=0;
        while(c0!=count || c1!=count || c2!=count){
            int extra_zeros = c0-count;
            if(extra_zeros>0){
                // dbg(extra_zeros);
                c1+=extra_zeros;
                c0-=extra_zeros;
                ans+=extra_zeros;
            }
            if(c0==count && c1==count && c2==count) break;
            int extra_ones = c1-count;
            if(extra_ones>0){
                // dbg(extra_ones);
                c2+=extra_ones;
                c1-=extra_ones;
                ans+=extra_ones;
            }
            if(c0==count && c1==count && c2==count) break;
            int extra_twos = c2-count;
            if(extra_twos>0){
                // dbg(extra_twos);
                c0+=extra_twos;
                c2-=extra_twos;
                ans+=extra_twos;
            }
        }
        cout<<ans<<endl;
    }
}