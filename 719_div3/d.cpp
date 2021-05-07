#include<bits/stdc++.h>
using namespace std;
long long combine(long long a){
    return a*(a-1)/2;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int  arr[n+1];
        for(int i=1;i<n+1;i++){
            cin>>arr[i];
            arr[i] = arr[i]-i;
        }
        map <int, long long> freq;
        long long ans = 0;
        for(int i=1;i<n+1;i++){
            freq[arr[i]]++;
        }
        // for(auto it=freq.begin(); it!=freq.end();it++){
        //     cout<<it->first<<" "<<it->second<<endl;
        // }
        for(auto it=freq.begin(); it!=freq.end();it++){
                ans+= combine(it->second);
        }
        cout<<ans<<"\n";
        // cout<<combine(1);
    }
}