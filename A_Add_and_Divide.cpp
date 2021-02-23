#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        int prev=40;
        int curr_,i=0,z;
        if(b==1){
            b++;
            curr_++;
        }
       for(;i<=30;i++){
           z=a;
           curr_=0;
           while(z>0){
               z/=(b+i);
               curr_++;
           }
           curr_+=i;
            prev=min(curr_,prev);
       }
       cout<<prev<<endl;
    }
    return 0;
}