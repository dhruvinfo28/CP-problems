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
        int n; cin>>n; int arr[n]; inputA(arr,n);
        unordered_set <int> us;
        string ans = "NO";
        for(int i=0;i<n;i++){
            if(us.find(arr[i])==us.end()){
                us.insert(arr[i]);
            }
            else{
                ans = "YES";
                break;
            }
        }
        cout<<ans<<"\n";

    }

    return 0;
}