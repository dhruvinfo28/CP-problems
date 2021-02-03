#include<bits/stdc++.h>
using namespace std;
void BFS(vector <int> adj[], int source, bool visited[], int candy[])
{
    queue <int> q; q.push(source);
    visited[source] = true;
    int candies;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto s: adj[curr]){
            if(!visited[s]){
                q.push(s);
                visited[s] = true;
            }
        }
    }

}
int main(){
    int n; cin>>n; int candy[n+1];
    for(int i=1;i<n+1;i++){
        cin>>candy[i];
    }
    vector <int> adj[n+1];
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool visited[n+1];
    for(int i=0;i<n+1;i++){
        visited[i] = false;
    }
    for(int i=1;i<n;i++){
        if(candy[i]==1){
            BFS(adj,i,visited,candy);
            break;
        }
    }
    int count=0;
    for(int i=1;i<n+1;i++){
        if(candy[i]!=1 && visited[i]){
            count++;
        }
    }
    cout<<(count * (count-1))/2<<endl;
    return 0;
}