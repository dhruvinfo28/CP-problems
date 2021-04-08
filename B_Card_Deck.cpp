#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int curr = n;
        while(curr>0){
            int curr_max = INT_MIN;
            int max_index;
            for(int i=0;i<curr;i++){
                if(arr[i]>curr_max){
                    curr_max = arr[i];
                    max_index = i;
                }
            }
            for(int i= max_index;i<curr;i++){
                cout<<arr[i]<<" ";
            }
            curr = max_index;
        }cout<<"\n";
    }
    return 0;
}