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
    int n; cin>>n; 
    long long x,p[n]; cin>>x; inputA(p,n);
    sort(p,p+n);
    long ans{0};
    long long curr_sum{0};
    int start=0, end = n-1;
    while(start<=end){
        curr_sum = p[start]+p[end];
        if(curr_sum<=x){
            ans++;
            start++;
            end--;
        }
        else{
            end--;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}