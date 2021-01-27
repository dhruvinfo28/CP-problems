#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<':'<<x<<endl;
#define l long
using namespace std;
template <class element_type>
void inputA(element_type *arr,int n){
    for(int i=0;i<n;i++){
         cin>>arr[i];
    }
}
template <class T>
void inputV(vector <T> &v){
    for(size_t i=0;i<v.size();i++){
          cin>>v[i];
    }
}
template <class T>
void printV(vector <T> arr){
    for(auto s: arr){
        cout<<s<<' ';
    }
}
template <class T>
void printA(T *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    l n,m,k; cin>>n>>m>>k; l a[n], b[m]; inputA(a,n); inputA(b,m);
    unordered_set <l> us;
    
    return 0;
}