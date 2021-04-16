#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<pair<int,int>> vec;
    int l,r;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        vec.push_back({l,1});
        vec.push_back({r,-1});
    }
    sort(vec.begin(),vec.end());
    int curr_ =0 , max_ = INT_MIN;
    for(int i=0;i<vec.size();i++){
        if(vec[i].second == 1){
            curr_++;
        }else{
            curr_--;
        }
        max_=max(max_,curr_);
    }
    cout<<max_<<"\n";
    
    return 0;
}