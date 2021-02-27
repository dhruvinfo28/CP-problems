#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull minimum(ull a, ull b,ull c){
    ull min_ = a;
    b = min(b,c);
    min_ = min(a,b);
    return min_;
}
int main(){
    int t; cin>>t;
    while(t--){
        ull p,a,b,c; cin>>p>>a>>b>>c;
        ull x,y,z;
        if(p%a!=0){
            x = a* ((p/a)+1);
        }else{
            x = a*(p/a);
        }
        if(p%b!=0){
            y = b* ((p/b)+1);
        }else{
            y = b*(p/b);
        }
        if(p%c!=0){
            z = c* ((p/c)+1);
        }else{
            z = c*(p/c);
        }
        cout<<minimum(x,y,z) - p<<"\n"; 
    }
}