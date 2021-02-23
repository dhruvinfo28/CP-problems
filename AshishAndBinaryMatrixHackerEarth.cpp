#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        string arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        bool flag = true;
        for(int del=0;del<m;del++){
            unordered_set<string> us;
            int i=0;
            flag = true;
            while(i<n){
                string s="";
                for(int j=0;j<del;j++){
                   s+=arr[i][j];
                }
                for(int j=del+1;j<m;j++){
                    s+=arr[i][j];
                }
                if(us.find(s)==us.end()){
                    us.insert(s);
                }else{
                    flag = false;
                    break;
                }
                i++;
            }
            if(flag) break;
        }
        if(flag) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }
    //Time complexity mnlogn
    return 0;
}