#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<':'<<x<<endl;
#define ll long long
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
    ll n,m,k; cin>>n>>m>>k; ll a[n], b[m]; inputA(a,n); inputA(b,m);
    sort(a,a+n); sort(b,b+m);
    ll ans{0};
    ll j{0};
    //After sorting we check one apartment for every tenant O(n^2)
    //Better if the current tenant finds that the apartment we are checking is less for him then it is less for all tenants ahead of him , so we break
    //Now when we find an apartment for a tenant, all the tenants before it has less requirements thus the apartment that was chosen was big for them hence all the coming apartments will be big for these previous tenants hence we start from where we left + 1 as where we left was alloted
    for(ll i=0;i<m;i++){
        for(;j<n;j++){
            if(b[i]<a[j]-k){
                break;
            }
            if(b[i]<=a[j]+k && b[i]>=a[j]-k){
                ans++;
                j++;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}