#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map <int,int> arr;
        for(int i=0;i<n;i++){
            int x; cin>>x;
            arr[x]++;
        }
        priority_queue<int> q;
        for(auto it = arr.begin(); it!=arr.end();it++){
            q.push(it->second);
        }
        int sz =n;
        while(q.size()>=2){
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            first--; 
            second--;
            sz-=2;
            if(first){
                q.push(first);
            }
            if(second){
                q.push(second);
            }  
        }
        if(!q.empty()){
            cout<<q.top()<<"\n";
        }
        else{
            cout<<0<<"\n";
        }
        //After we get the frequency array
        // Then each operation — take two non-zero numbers and subtract one from them. In the end, we will have only one non-zero number left, and we want to minimize it. We can say that we want to minimize the maximum number after applying all the operations, which means we want to minimize the maximum number at each step.
        // We get the following greedy solution — each time we take two characters with maximal occurrences number and delete them.
        

        //Assume that in every query from the frequency structure we built , we fetch the two largest decrease them by one and then push them back again if they are non zero , we do it until there is only one element left in the structure.
        //So for doing these kind of queries a max heap would be beneficial , we fetch the two largest in logn time and update them and push them to their correct position in logn time, 
        //Hence overall complexity will not exceed nlogn

        //For this purpose we'll use STL priority queue , designed such that it has the elements in non increasing order always, the maximum is always popped and new element is pushed according to the priority

    }
    return 0;
}