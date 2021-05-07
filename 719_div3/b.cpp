#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n<=9){
            cout<<n<<"\n";
        }else{
            int length = 0;
            int last;
            int dummy = n;
            while(n!=0){
                length++;
                last=n%10;
                n=n/10;
            }
            int ans = 9 * (length-1) + (last-1);
            string curr = to_string(last);
            for(int i=0;i<length-1;i++){
                curr+=to_string(last);
            }
            int check = stoi(curr);
            if(dummy>=check){
                ans+=1;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}