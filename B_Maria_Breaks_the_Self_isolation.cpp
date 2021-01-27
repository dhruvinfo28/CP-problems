#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<':'<<x<<endl;
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
    int t; cin>>t;
    while(t--){
        int n; cin>>n; vector<long> arr(n); inputV(arr);
        sort(arr.begin(),arr.end());
        long ans = 1;
        for(int i=0;i<n;i++){
            if(i+1>=arr[i]){
                ans = i+1;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}