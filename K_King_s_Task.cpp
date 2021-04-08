#include<bits/stdc++.h>
using namespace std;
void operation_1(vector<int> &arr){
    for(int i=0;i<arr.size()-1;i+=2){
        swap(arr[i],arr[i+1]);
    }
}
void operation_2(vector<int> &arr){
    for(int i=0;i<arr.size()/2;i++){
        swap(arr[i], arr[i+ arr.size()/2]);
    }
}
bool check(vector<int> arr){
    for(int i=0;i<arr.size()-1; i++){
        if(arr[i]>=arr[i+1]){
            return false;
        }
    }
    return true;
}

//The key point here is applying the same operation consecutively returns the orignal sequence back, hence sequence has to be 1 2 1
// or 2 1 2
//Next the outputs after operations will be periodic , i.e. after every 2*n operations we will get the same sequence back
//Note that these operations are either 1 2 1... or 2 1 2 ...
//Hence loop from 0 to 2n-1 perform operations and check if it got sorted or not , if it did, choose the minimum number of operations 
//obtained from sequence one (121) and sequence two (212) else print -1
int main(){
    int n; cin>>n;
    vector <int> arr(2*n);
    for(int i=0;i<2*n;i++){
        cin>>arr[i];
    }
    // 1 2 1
    if(check(arr)){
        cout<<0<<"\n";
        return 0;
    }
    vector <int> test = arr;
    int ans = 0;
    for(int i=0;i<2*n;i++){
        if(i%2!=0){
            operation_1(test);
            if(check(test)){
                ans = i+1;
                break;
            }
        }
        else{
            operation_2(test);
            if(check(test)){
                ans = i+1;
                break;
            }
        }
    }
    test = arr;
    int ans2 = 0;
    for(int i=0;i<2*n;i++){
        if(i%2==0){
            operation_1(test);
            if(check(test)){
                ans2 = i+1;
                break;
            }
        }
        else{
            operation_2(test);
            if(check(test)){
                ans2 = i+1;
                break;
            }
        }
    }
    if(ans!=0 && ans2!=0) ans = min(ans,ans2);
    else if(ans==0 && ans2!=0) ans = ans2;
    else if(ans!=0 && ans2==0) {}
    else if(ans==0 && ans2==0) ans = -1;

    cout<<ans<<"\n";
    return 0;
}