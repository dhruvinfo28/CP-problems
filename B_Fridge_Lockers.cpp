#include<iostream>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m; int arr[n+1]; 
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        if(n==2){
            cout<<-1<<"\n";
        }
        else if(n==m){
            long cost = 0;
            for(int i=1;i<n;i++){
                cost += arr[i] + arr[i+1];
            }
            cost+=arr[n] + arr[1];
            cout<<cost<<"\n";
            for(int i=1;i<n;i++){
                cout<<i<<" "<<i+1<<"\n";
            }
            cout<<n<<" "<<1<<"\n";
        }
        else{
            cout<<"-1"<<"\n";
        }
    }
    return 0;
}