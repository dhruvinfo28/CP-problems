#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
using namespace std;
void dfs(vector<int> adj[], int source, vector<bool> &visited){
    visited[source] = true;
    for(auto s: adj[source]){
        if(!visited[s]){
            dfs(adj,s,visited);
        }
    }
}
int main(){
    fast
    int n,m; cin>>n>>m;
    vector<int> adj[n+1];
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //Idea, find disconnected components(or how many disconnections are there) in the graph and add an edge between them
    vector<bool> visited(n+1,false);
    vector<int> disconnected_heads;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            disconnected_heads.push_back(i);
            dfs(adj,i,visited);
        }
    }
    cout<<(int)(disconnected_heads.size()-1)<<"\n";
    for(int i=1;i<(int)disconnected_heads.size();i++){
        cout<<disconnected_heads[i]<<" "<<disconnected_heads[i-1]<<"\n";
    }

    return 0;
}