#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n==2){
            cout<<"-1\n";
        }else{
            int arr[n][n];
            int count = 1;
            for(int i=0;i<n;i++){
                arr[i][i] = count;
                count++;
            }
            for(int j=1;j<n;j++){
                for(int i=0;i<n;i++){
                    if(i+j<n){
                        arr[i+j][i] = count;
                        count++;
                    }else{
                        break;
                    }
                }
                for(int i=0;i<n;i++){
                    if(i+j<n){
                        arr[i][i+j] = count;
                        count++;
                    }else{
                        break;
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<arr[i][j]<<" ";
                }cout<<"\n";
            }
        }
    }
    return 0;
}