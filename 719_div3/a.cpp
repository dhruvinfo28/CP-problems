#include<bits/stdc++.h>
using namespace std;
bool check(int *freq_of,string s){
    for(int i=0;i<s.length();i++){
        char curr = s[i];
        while(s[i]==curr){
            freq_of[curr-'A']--;
            i++;
        }
        i--;
        if(freq_of[curr-'A']!=0){
            return false;
        }
    }
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int freq_of[26];
        memset(freq_of,0,sizeof(freq_of));
        for(int i=0;i<n;i++){
            freq_of[s[i]-'A']++;
        }
        if(check(freq_of,s)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}