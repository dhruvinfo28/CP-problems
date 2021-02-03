#include<bits/stdc++.h>
using namespace std;
bool helper(vector <int> adj[],int source, bool visited[], int coming_from){
    visited[source] = true;
    for(auto s: adj[source]){
        if(!visited[s]){
            if(helper(adj,s,visited,source)){
                return true;
            }
        }
        else if(s!=coming_from){
            return true;
        }
    }
    return false;
}
bool check_cycle(vector <int> adj[], int n){
    bool visited[n]; 
    for(int i=1;i<n+1;i++){
        visited[i] = false;
    }
    for(int i=1;i<n+1;i++){
        if(!visited[i]){
            if(helper(adj,i,visited,-1)){
                return true;
            }
        }
    }
    return false;
}
void BFS(vector <int> adj[], int source, bool visited[], int teams[]){
    queue<int> q; q.push(source); visited[source] = true;
    while(!q.empty()){
        int set;
        int curr = q.front();
        q.pop();
        if(teams[curr]==1){
            set = 2;
        }else{
            set = 1;
        }
        for(auto s: adj[curr]){
            if(!visited[s]){
                teams[s] = set;
                visited[s] = true;
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //First check if there is a cycle: if cycle then it is not possibe cause a cycle contains minimum three vertices and then it gets impossible to separate these three in two teams without a team having atleast two friends
    //This was the initial thing, but if u see closely if we have a cycle of length 4, then those four people can be seperated into two different teams , so the gist is no graph with a cycle of length three will be accepted, rest can be divided
    bool check = check_cycle(adj,n);
    // cout<<check<<endl;
    if(!check){
        bool visited[n+1]; 
        int teams[n+1];
        for(int i=1;i<n+1;i++){
            visited[i] = false;
            teams[i] = 1;
        }
        teams[1] = 1;
        for(int i=1;i<n+1;i++){
            if(!visited[i]){
                BFS(adj,i,visited,teams);
            }
        }
        for(int i=1;i<n+1;i++){
            cout<<teams[i]<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE"<<"\n";
    }
}