// A path doesn't have repeating vertices
#include<bits/stdc++.h>
using namespace std;
void dfs(vector <int> adj[], int source, int destination, bool visited[],string path, vector<string> &total_paths){
    path+="->" + to_string(source);
    visited[source] = true;
    if(source==destination){
        total_paths.push_back(path);
        path.pop_back();
        visited[source] = false;
        return;
    }
    for(auto s: adj[source]){
        if(!visited[s]){
            dfs(adj,s,destination,visited,path,total_paths);
        }
    }
    //Imagine source was four and its adjacents 2 and 3 all visited, so when we end the for loop , and we go back to the
    //function call where 4 was in adjacents and we start visiting siblings of 4, we need 4 to be removed
    //Hence here we make visited[4] = false
    //and pop it out of the path string
    visited[source] = false;
    path.pop_back();
}
int main(){
    int n,m; cin>>n>>m ;
    vector<int> adj[n+1];
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //All paths from 3 to n-1 (Change accordingly)
    int source = 3, destination = n-1; 
    string path = "";
    vector<string> total_paths;
    bool visited[n+1];
    memset(visited,sizeof(visited), false);
    dfs(adj,source,destination,visited,path,total_paths);
    for(auto s: total_paths){
        cout<<s<<endl;
    }
    return 0;
}