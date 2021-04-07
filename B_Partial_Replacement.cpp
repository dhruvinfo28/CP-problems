#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        string s; cin>>s;
        int count = 0;
        auto first = s.find('*');
        if(first!= string::npos){
            s[first] = 'X';
            count++;
        }
        auto last = s.find_last_of('*');
        if(last!=string::npos){
            s[last] = 'X';
            count++;
        }
        int numberOfX = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='X'){
                numberOfX++;
            }
        }
        for(int i=0;i<s.length(); i++){
            if(s[i]=='X'){
                    numberOfX--;
                    if(!numberOfX) break;
                    int j = 0;
                    bool flag = false;
                    while(j+i+1<s.length() && j<k){
                        if(s[j+i+1]=='X'){
                            flag = true;
                            break;
                        }
                        j++;
                    }
                    
                    int x = i+j;
                    if(!flag && j+i<s.length()){     
                        while(s[x]=='.'&& x>i){
                            x--;
                        }
                        s[x]='X';
                        numberOfX++;
                        count++;
                    }
                    i =x-1;
            }
        }
        cout<<count<<"\n";
        
    }
    return 0;
}