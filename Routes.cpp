#include<bits/stdc++.h>
using namespace std;
struct triplet{
    int first,second,third;
    triplet(int a,int b,int c):first{a}, second{b},third{c}{}
};
int pick_source(int cost[],bool all[], int n){
    int min_ = INT_MAX;
    int ret;
    for(int i=1;i<n+1;i++){
        if(cost[i]<=min_ && all[i]){
            min_ = cost[i];
            ret = i;
        }
    }
    all[ret] = false;
    return ret;
}
bool check(bool all[], int n){
    for(int i=1;i<n+1;i++){
        if(all[i]){
            return false;
        }
    }
    return true;
}
bool BFS(int source, int dest,vector <triplet> adj[],int n){
    bool visited[n+1];
    for(int i=1;i<n+1;i++){
        visited[i] = false;
    }
    queue <int> q;
    q.push(source);
    visited[source] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto s: adj[curr]){
            if(!visited[s.first]){
                q.push(s.first);
                visited[s.first] = true;
            }
        }
    }
    if(visited[dest]){
        return true;
    }else{
        return false;
    }
}
int main(){
    int k,n,x; cin>>k>>n>>x;
    vector <triplet> adj[n+1];//Total cost as edge
    int s,d,t,c;
    int weight;
    for(int i=0;i<x;i++){
        cin>>s>>d>>t>>c;
        weight=c+ t*k;
        adj[d].push_back(triplet(s,weight,t));
        adj[s].push_back(triplet(d,weight,t));
    }
    int source, destination; cin>>source>>destination;
    if(!BFS(source,destination,adj,n)){
        cout<<"Error"<<endl;
        return 0;
    }
    bool all[n+1];
    for(int i=0;i<n+1;i++){
        all[i] = true;
    }
    int cost[n+1],parents[n+1],time[n+1];
    for(int i=0;i<n+1;i++){
        cost[i] = INT_MAX;
        time[i] = INT_MAX;
    }
    parents[source] = -1;
    cost[source] = time[source] = 0;
    while(!check(all,n)){
        int source = pick_source(cost,all,n);
        for(auto s:adj[source]){
            if(cost[s.first]>s.second+cost[source]){
                cost[s.first] = cost[source]+s.second;
                parents[s.first] = source;
                time[s.first] = s.third + time[source];
                if(s.first!=destination){
                    cost[s.first]+=k;
                    time[s.first]+=1;
                }
            }
        }
    }
    int i = destination;
    vector <int> route;
    while(i!=-1){
        route.push_back(i);
        i=parents[i];
    }
    reverse(route.begin(),route.end());
    for(int i=0;i<route.size()-1;i++){
        cout<<route[i]<<"->";
    }cout<<route[route.size()-1]<<" ";
    cout<<time[destination]<<" "<<cost[destination]<<endl;
    return 0;
}