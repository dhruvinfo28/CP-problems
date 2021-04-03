#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int64_t n,m,x; cin>>n>>m>>x;
        if(x%n!=0){
            cout<<((x%n-1)*m) + (x/n+1)<<"\n";
        }else{
            cout<<((n-1)*m) + (x/n)<<"\n";
        }
    }
    return 0;
}