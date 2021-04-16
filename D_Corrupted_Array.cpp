#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n+2);
        ull sum=0;
        for(int i=0;i<n+2;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
            sum+=(ull)arr[i];
        }
        if(sum>arr[n+1]){
            //If sum of first n is greater than the last, then we can't add arr[n] and remove some element from sum to make the total equal to arr[n+1], hence not possible
            cout<<"-1"<<"\n";
        }else{
            // If sum equal to any of the two we got the answer
            if(sum==arr[n] || sum==arr[n+1]){
                for(int i=0;i<n;i++){
                    cout<<arr[i]<<" ";
                }cout<<"\n";
            }
            else{
                //If sum is less than arr[n+1] we can make sum = arr[n+1] by including arr[n] and removing some element from the previous sum
                //sum+arr[n]-some_no = arr[n+2]
                //sum+arr[n]-arr[n+2] = some_no;
                //So if we find the LHS of above in a set , we the answer is possible
                //Since repeating elements were possible we use a map , to have frequency
                auto it = freq.find(sum+arr[n]-arr[n+1]);
                if(it!= freq.end()){
                    cout<<arr[n]<<" ";
                    for(auto x=freq.begin(); x!=freq.end();x++){
                        //We need to print all numbers except that found element, if found element is repeating we need to print it
                        //one less time than its frequency
                        if(x==it){
                            while(x->second>1){
                                cout<<x->first<<" ";
                                x->second--;
                            }
                        }else{
                            while(x->second>0){
                                cout<<x->first<<" ";
                                x->second--;
                            }
                        }
                    }cout<<"\n";

                }else{
                    cout<<"-1\n";
                }
            }
        }
    }
}