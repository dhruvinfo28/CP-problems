#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
bool comparator(ull &a, ull &b){
    return a>b;
}
int main(){
    int t; cin>>t;
    while(t--){
        ull n; cin>>n; ull u[n], s[n];
        map<ull,vector<ull>> pools;
        for(size_t i=0; i<n;i++){
            cin>>u[i];
        }
        for(size_t i=0; i<n;i++){
            cin>>s[i];
        }
        for(size_t i=0; i<n;i++){
            pools[u[i]].push_back(s[i]);
        }
        for(auto it = pools.begin(); it!=pools.end(); it++){
            sort(it->second.begin(),it->second.end(),comparator);
            ull curr = 0;
            for(int i=0;i<it->second.size();i++){
                it->second[i] = curr+it->second[i];
                curr = it->second[i];
            }
        }
        //This will give a TLE
        // for(int i=1;i<=n;i++){
        //     ull curr_ans = 0;
        //     for(auto it=pools.begin();it!=pools.end();it++){
        //         ull teams = (it->second.size())/i;
        //         if(teams!=0){
        //             curr_ans+=it->second[(teams*i)-1];
        //         }
        //     }
        //     cout<<curr_ans<<" ";
        // }

        //This won't : the reason being we dont have to check for all team sizes from 1 to n for a particular university as 
        //unversity won't have teams for k>student size of a university
        //Secondly we create a vector which is the ans itself
        //We traverse our map and for every university we calculate skillset for team size 1 to total number of students in that
        //university
        vector<ull> ans(n+1,0);
        for(auto i: pools){
            ull curr_size = i.second.size();
            for(int j=1;j<=curr_size; j++){
                ull teams = curr_size/j;
                ans[j]+=i.second[(teams*j)-1];
            }
        }
        for(int i=1;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}