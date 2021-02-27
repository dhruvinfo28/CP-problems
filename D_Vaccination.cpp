//Heurestics 49 , learn knapsack 0-1
#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<ll,ll> bfs(int source, vector <int> adj[],bool visited[],int a[]){
    ll cases = 0;
    ll cities=0;
    queue<int> q;
    q.push(source);
    visited[source] = true;
    cases+=(ll)a[source];
    cities++;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto s: adj[curr]){
            if(!visited[s]){
                q.push(s);
                visited[s]=true;
                cases+=(ll)a[s];
                cities++;
            }
        }
    }
    return make_pair(cases,cities);
} 
bool sortBysec(pair<ll,ll> &a, pair<ll,ll> &b){
    if(a.second == b.second){
        return a.first>b.first;
    }
    else{
        return a.second < b.second;
    }
}
bool sortByfirst(pair<ll,ll> &a, pair<ll,ll> &b){
    if(a.first==b.first){
        return a.second > b.second;
    }
    return a.first<b.first;
}
int main(){
    int n,m,k; cin>>n>>m>>k;
    int a[n+1];
    a[0]=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector <int> adj[n+1];
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    vector<pair<ll,ll>> areas;
    for(int i=1;i<n+1;i++){
        if(!visited[i]){
           areas.push_back(bfs(i,adj,visited,a));
        }
    }
    sort(areas.begin(),areas.end(),sortByfirst);
    ll k_ = k;
    ll ans1=0;
    for(int i=0;i<areas.size();i++){
            if(areas[i].first<=k_){
                k_-=areas[i].first;
                ans1+=areas[i].second;
            }
    }
    sort(areas.begin(),areas.end(),sortBysec);
    reverse(areas.begin(),areas.end());
    ll ans2=0;
    k_ = k;
    for(int i=0;i<areas.size();i++){
        if(areas[i].first<=k_){
            k_-=areas[i].first;
            ans2+=areas[i].second;
        }
    }
    cout<<max(ans1,ans2)<<endl;
    return 0;
}