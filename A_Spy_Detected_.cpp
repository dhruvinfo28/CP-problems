#include<bits/stdc++.h>
using namespace std;
int main(){
    int t ; cin>>t;
    int freq[101];
    while(t--){
        int n; cin>>n;
        memset(freq,0,sizeof(freq));
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            freq[arr[i]]++;
        }
        int ans;
        for(int i=1;i<101;i++){
            if(freq[i]==1){
                ans = i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==ans){
                cout<<i+1<<"\n";
            }
        }
        
    }
    return 0;
}