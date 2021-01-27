#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> g[n+1];
    int curr;
    for(int i=1;i<=n-1;i++){
        cin>>curr;
        g[curr].push_back(i+1);
    }
    int leaf_child;
    bool flag = true;
    for(int i=1;i<n;i++){
        leaf_child = 0;
        if(g[i].size()!=0){
            for(auto s:g[i]){
                if(g[s].size()==0){
                    leaf_child++;
                }
            }
            if(leaf_child<3){
                flag = false;
                break;
            }
        }
    }
    if(flag){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}