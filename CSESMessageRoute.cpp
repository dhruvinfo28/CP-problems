#include<bits/stdc++.h>
using namespace std;
void insert(vector<int> adj[], int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void BFS(int source,vector <int> adj[], int parent[], bool visited[]){
    visited[source] = true;
    queue < int> q; q.push(source);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto s: adj[curr]){
            if(!visited[s]){
                visited[s] = true;
                q.push(s);
                parent[s] = curr;
            }
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    vector <int> adj[n+1];
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        insert(adj,a,b);
    }
    int parent[n+1];
    bool visited[n+1];
    for(int i=0;i<n+1;i++){
        parent[i] = 0;
        visited[i] = false;
    }
    BFS(1,adj, parent,visited);
    if(visited[n]){
        vector <int> ans;
        int i=n;
        long long l=0;
        while(i!=1){
            l++;
            ans.push_back(i);
            i = parent[i];
        }
        ans.push_back(1);
        cout<<l+1<<"\n";
        reverse(ans.begin(), ans.end());
        for(auto s:ans){
            cout<<s<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}