#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int curr_max, curr_min;
        long ans=0;
        for(int i=0;i<n-1;i++){
            curr_max = max(arr[i],arr[i+1]);
            curr_min = min(arr[i],arr[i+1]);
            while(curr_max>2*curr_min){
                curr_min*=2;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}