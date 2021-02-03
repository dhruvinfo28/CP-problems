#include<iostream>
#define dbg(x) cout<<#x<<":"<<x<<endl;
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; string s; cin>>s;
        string first_four = s.substr(0,4);
        // dbg(first_four);
        string last_four = s.substr(n-4,4);
        // dbg(last_four);
        string first_three = s.substr(0,3);
        first_three+=s[n-1];
        // dbg(first_three);
        string first_two = s.substr(0,2);
        first_two += s[n-2];
        first_two += s[n-1];
        // dbg(first_two);
        string first_one = s[0] + s.substr(n-3,3);
        // dbg(first_one);
        if(first_four=="love" || last_four == "love" || first_three =="love" || first_two =="love" || first_one =="love"){
            cout<<"YES"<<"\n";
        } else{
            cout<<"NO"<<"\n";
        }
    }
}