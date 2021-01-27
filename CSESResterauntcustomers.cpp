#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<pair<int,int>> vec;
    int l,r;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        vec.push_back(make_pair(l,1));
        vec.push_back(make_pair(r,-1));
    }
    sort(vec.begin(), vec.end());
    int max_sum = 0;
    int prefix_sum  = 0;
    for(int i=0;i<n;i++){
        prefix_sum += vec[i].second;
        if(prefix_sum<=0){
            prefix_sum = 0;
        }
        max_sum = max(prefix_sum, max_sum);
    }
    cout<<max_sum<<endl;
    return 0;
}