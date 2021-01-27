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
    int n,m; cin>>n>>m; long tickets[n], customer_p[m]; inputA(tickets, n); inputA(customer_p, m);
    sort(tickets,tickets+n);
    pair<long, int> customer[m];
    for(int i=0;i<m;i++){
        customer[i].first = customer_p[i];
        customer[i].second = i;
    }
    for(int i=0;i<m;i++){
        customer_p[i] = -1;
    }
    sort(customer, customer+m);
    // printA(tickets,n); cout<<endl;
    // for(int i=0;i<m;i++){
    //     cout<<customer[i].first<<" ";
    // }cout<<endl;
    // for(int i=0;i<m;i++){
    //     cout<<customer[i].second<<" ";
    // }cout<<endl;
    int j =0;
    for(int i=0;i<m;i++){
        while(j<n){
            // dbg((customer[i].first));
            if(tickets[j]>customer[i].first){
                    // dbg(tickets[j-1]);
                    customer_p[customer[i].second] = tickets[j-1];
                
                    break;
            }
            else if(tickets[j]==customer[i].first){
                    // dbg(tickets[j]);
                    customer_p[customer[i].second] = tickets[j];
                    tickets[j] = -1;
                    j++;
                    break;
            }
            j++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<customer_p[i]<<"\n";
    }
    return 0;
}