#include<iostream>
#include<string>
using namespace std;
bool check_way_out(string s, int index){
    int point =  index-1;
    if(point<0){
        point = s.length() -1;
    }
    if(s[point]=='-'){
        return true;
    }
    bool flag = s[point] != '>';
    if(!flag){
        return flag;
    }
    int previous = (index-2) ;
    if(previous<0){
        previous+=s.length();
    }
    while(previous!=point){
        if(s[previous] == '>'){
            return false;
        }
        previous--;
        if(previous<0){
            previous+=s.length();
        }
    }
    return true;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; string s; cin>>s;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='-'){
                ans++;
            }
            else if(s[i]=='>'){
               int previous = i-1;
               if(i-1<0){
                   previous+=n;
               } 
               if(s[previous] == '-'){
                   ans++;
                   continue;
               }
               if(s[previous] == '<'){
                   continue;
               }
               int point = i+1;
               int local_count = 1;
               bool flag = false;
               while(point!=i){
                    if(s[point]=='>'){
                        local_count++;
                    }
                    else{
                        i = point;
                        flag = true;
                        break;
                    }
                   point++;
                   point = point%n;
               }
               if(flag==false){
                   ans+=local_count;
                   break;
               }
            }
            else{
                int previous = i-1;
                if(previous<0){
                    previous+=n;
                }
                if(s[previous=='-']){
                    ans++;
                    continue;
                }
                
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}