#include<bits/stdc++.h>
using namespace std;
vector <int> Topological_sort(vector <int> adj[], int indegree[], int v){
    vector <int> ans;
    int count = 0;
    queue <int> q;
    for(int i=1;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(auto s: adj[curr]){
            indegree[s]--;
            if(indegree[s]==0){
                q.push(s);
            }
        }
        count++;
    }
    vector <int> a;
    if(count!=v-1){
        return a;
    }else{
        return ans;
    }
}
int main(){
    int n,m; cin>>n>>m;
    vector <int> adj[n+1];
    int a,b; 
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    int indegree[n+1];
    for(int i=0;i<n+1;i++){
        indegree[i] = 0;
    }
    for(int i=0;i<n+1;i++){
        for(auto s: adj[i]){
            indegree[s] ++;
        }
    }
    vector <int> ans = Topological_sort(adj,indegree,n+1);
    if(ans.size()!=0){
        for(auto s: ans){
            cout<<s<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE"<<"\n";
    }
}