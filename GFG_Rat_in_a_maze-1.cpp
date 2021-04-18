#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void dfs(vector<vector<int>> m, int sourceX, int sourceY,int n, bool *visited[],string path, vector<string> &ans){
        //Base condition
        if(sourceX==n-1 && sourceY==n-1){
            ans.push_back(path);
            path="";
            return;
        }
        //Here find adjacents to where the rat can go
        //Seeing if it can go left
        visited[sourceX][sourceY] = true;
        if(sourceY>0 && m[sourceX][sourceY-1]!=0 && !visited[sourceX][sourceY-1]){
            //Yes can go left
            path+='L';
            dfs(m,sourceX,sourceY-1,n,visited,path,ans);
            visited[sourceX][sourceY-1] = false;
            path.pop_back();
        }
        //Right
        if(sourceY<n-1 && m[sourceX][sourceY+1]!=0 && !visited[sourceX][sourceY+1]){
            //Yes can go right
            path+='R';
            dfs(m,sourceX,sourceY+1,n,visited,path,ans);
            visited[sourceX][sourceY+1] = false;
            path.pop_back();
        }
        //Up
        if(sourceX>0 && m[sourceX-1][sourceY]!=0 && !visited[sourceX-1][sourceY]){
            path+='U';
            dfs(m,sourceX-1,sourceY,n,visited,path,ans);
            visited[sourceX-1][sourceY] = false;
            path.pop_back();
        }
        //Down
        if(sourceX<n-1 && m[sourceX+1][sourceY]!=0 && !visited[sourceX+1][sourceY]){
            path+='D';
            dfs(m,sourceX+1,sourceY,n,visited,path,ans);
            visited[sourceX+1][sourceY] = false;
            path.pop_back();
        }
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans; 
        if(m[0][0]==0){
            return ans;
        }
        string path="";
        bool *arr[n];
        for(int i=0;i<n;i++){
            arr[i] = new bool[n];
            for(int j=0;j<n;j++){
                arr[i][j] = false;
            }
        }
        
        dfs(m,0,0,n,arr,path,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
int main(){

    return 0;
}