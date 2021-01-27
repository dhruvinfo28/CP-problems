#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<":"<<x<<endl;
using namespace std;
int main(){
    int n,m; cin>>n>>m; string arr="",a;
    for(int i=0;i<n;i++){
        cin>>a;
        arr+=a;
    }
    // cout<<arr<<endl;
    int source, end;
    for(int i=0;i<n*m;i++){
        if(arr[i]=='A'){
            source = i;
        }
        if(arr[i]=='B'){
            end = i;
        }
    }
    // dbg(source);
    // dbg(end);
    int parent[n*m];
    bool visited[n*m];
    for(int i=0;i<n*m;i++){
        parent[i] = -1;
        visited[i] = false;
    }
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if((curr+m)<(n*m) && (curr+m)>=0){ //Down 
            if(arr[curr+m] == '.' || arr[curr+m] == 'B'){
                if(!visited[curr+m]){
                    // dbg((curr+m));
                    q.push(curr+m);
                    visited[curr+m] = true;
                    parent[curr+m] = curr;
                }
            }
        }
        if((curr-m)>=0 && (curr-m)<(n*m)){ //Top
            if(arr[curr-m] == '.' || arr[curr-m] == 'B'){
                if(!visited[curr-m]){
                    // dbg((curr-m));
                    visited[curr-m] = true;
                    q.push(curr-m);
                    parent[curr-m] = curr;
                }
            }
        }
        if(curr>=0 && (curr+1)%m!=0  && (curr+1)<(n*m)){ //right
            if(arr[curr+1] == '.' || arr[curr+1] == 'B'){
                if(!visited[curr+1]){
                    // dbg((curr+1));
                    visited[curr+1] = true;
                    q.push(curr+1);
                    parent[curr+1] = curr;
                }
            }
        }
        if((curr-1)>=0 && (curr)%m!=0 && (curr-1)<(n*m)){ //Left
            if(arr[curr-1] == '.' || arr[curr-1] == 'B'){
                if(!visited[curr-1]){
                    visited[curr-1] = true;
                    q.push(curr-1);
                    parent[curr-1] = curr;
                }
            }
        }
    }
    if(visited[end]){
        cout<<"YES"<<"\n";
        int i=end;
        long long l{0};
        vector <int> ans;
        while(i!=source){
            l++;
            ans.push_back(i);
            i = parent[i];
        }
        cout<<l<<"\n";
        ans.push_back(source);
        reverse(ans.begin(), ans.end());
        int previous = ans[0];
        for(int i=1;i<ans.size();i++){
            if(previous - ans[i]==1){
                cout<<"L";
            }
            if(previous+m==ans[i]){
                cout<<"D";
            }
            if(previous-ans[i]==-1){
                cout<<"R";
            }
            if(previous-m==ans[i]){
                cout<<"U";
            }
            previous = ans[i];
        }
    }else{
        cout<<"NO"<<"\n";
    }
}