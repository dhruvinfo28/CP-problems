#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n; int arr[n]; 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int curr_length =1 , max_length = INT_MIN;
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){
            curr_length++;
        }else{
            max_length = max(max_length,curr_length);
            curr_length = 1;
        }
    }
    max_length = max(max_length, curr_length);
    cout<<max_length<<"\n";
    return 0;
}