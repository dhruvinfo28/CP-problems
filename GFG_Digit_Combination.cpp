#include<bits/stdc++.h>
using namespace std;
string str = "!@*";
class comparison{
    public:
    bool operator()(string &a, string &b){
        return a>b;
    }
};
void permute(char *arr, int l, int r, string og, priority_queue<string, vector<string>, comparison> &ans){
    if(l>r){
        //Here we have our permutation
        int i = 0;
        string copy = og;
        for(int j=0;j<copy.length();j++){
            if(isdigit(copy[j])){
                copy[j] = arr[i];
                i++;
            }
        }
        ans.push(copy);
        return ;
    }
    else{
        for(int i=0;i<3;i++){
            arr[l] = str[i];
            permute(arr,l+1,r,og,ans);
        }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n=0;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                n++;
            }
        }
        if(n!=0){
            priority_queue<string,vector<string>, comparison> ans;
            char *arr = new char[n];
            permute(arr,0,n-1,s,ans);
            while(!ans.empty()){
                cout<<ans.top()<<" ";
                ans.pop();
            }cout<<endl;
        }else{
            cout<<s<<endl;
        }
    }
}