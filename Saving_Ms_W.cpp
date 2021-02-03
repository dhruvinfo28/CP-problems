//Hackerearth
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int pick_source(bool levels[],ll stamina[], int n){
    ll min_ = LONG_LONG_MAX;
    int ret;
    for(int i=0;i<n;i++){
        if(stamina[i]<=min_ && levels[i]){
            min_ = stamina[i];
            ret = i;
        }
    }
    levels[ret] = false;
    return ret;
}
int main(){
    int n,m,x,y; cin>>n>>m>>x>>y;
    vector <pair<ll,ll>> adj[n];
    ll a,b,w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    ll c[n], h[n];
    for(int i=0;i<n;i++){
        cin>>c[i]>>h[i];
    }

    ll staminaLevel{0};
    ll stamina[n]; stamina[x] = 0;
    for(int i =0 ;i<n;i++){
        if(i!=x)
            stamina[i] = LONG_LONG_MAX;
    }
    bool levelsNotDone[n];
    for(int i=0;i<n;i++){
        levelsNotDone[i] = true;
    }
    while(levelsNotDone[y]){
        int source = pick_source(levelsNotDone,stamina,n);
        levelsNotDone[source] = false;
        for(auto s:adj[source]){
            if(staminaLevel < stamina[source]+ s.second){
                staminaLevel = c[source];
                
            } else{
                if(stamina[source]+ s.second < stamina[s.first]){
                    stamina[s.first] = stamina[source]+ s.second; 
                    staminaLevel -= stamina[s.first];
                }
            }
        }
    }

    return 0;
}