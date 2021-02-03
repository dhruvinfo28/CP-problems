#include<bits/stdc++.h>
using namespace std;
void BFS(vector <int> adj[], int source, int add, int avoid,int c[],int n)
{
    bool visited[n+1];
    for(int i=1;i<n+1;i++){
        visited[i] = false;
    }
    queue <int> q; q.push(source);
    visited[source] = true;
    c[source]+=add;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto s: adj[curr]){
            if(!visited[s] && s!=avoid){
                q.push(s);
                visited[s]= true;
                c[s] +=add;
            }
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    vector <int> adj[n+1];
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int c[n+1];
    for(int i=1;i<n+1;i++){
        c[i] = 0;
    }
    int x,u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v>>x;
        BFS(adj,u,x,v,c,n);
    }
    for(int i=1;i<=n;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}