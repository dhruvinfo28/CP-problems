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
struct Movie{
    int dur,start,end;
    Movie(int a, int b): dur{b-a}, start{a}, end{b}{}
    bool operator<(Movie &rhs){
        return this->dur < rhs.dur ;
    }
};
int main(){
    int n; cin>>n;
    int l,r;
    vector <Movie> vec;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        vec.push_back(Movie(l,r));
    }
    sort(vec.begin(),vec.end());
    

    return 0;
}