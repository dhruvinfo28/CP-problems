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
        int n,ans=-1; cin>>n; int arr[n]; inputA(arr,n);
        bool flag = true;
        unordered_set<int> us;
        for(int i=1;i<1024;i++){
            us.clear();
            flag  = true;
            for(int j=0;j<n;j++){
                us.insert((arr[j]^i));
            }
            for(int j=0;j<n;j++){
                if(us.find(arr[j])==us.end()){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans = i;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}