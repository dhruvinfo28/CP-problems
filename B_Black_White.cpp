#include<iostream>
using namespace std;
char complement(char a){
    if(a=='0'){
        return '1';
    }else{
        return '0';
    }
}
int main(){
    string s; cin>>s;
    char prev = s[0];
    int count = 0;
    for(int i=1;i<s.length();i++){
        if(s[i]==prev){
            s[i] = complement(prev);
            count++;
        }
        prev = s[i];
    }
    cout<<count<<endl;
    return 0;
}