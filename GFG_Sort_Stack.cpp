#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   struct Helper{
     static void find_max(stack<int> &k,int &prev,bool &flag){
         if(k.empty()){
             return ;
         }
         int curr = k.top();
         if(curr>prev){
             prev = curr;
         }
         k.pop();
         find_max(k,prev,flag);
         if(curr!=prev || flag){
             k.push(curr);
         }else{
             //Once we find one curr = prev i.e the max in unwinding phase we dont push it and set flag = true so that 
             //we can push any more occurences of the same number back to the stack
             flag = true;
         }
     }  
   };
   
   stack <int> test;
   
   while(!s.empty()){
       int max_ = INT_MIN;
       bool flag = false;
       Helper::find_max(s,max_,flag);
       //After every call max_ is the maximum from remaining elements in the stack
    //   cout<<"MAx:"<<max_<<endl;
       test.push(max_);
   }
   while(!test.empty()){
       s.push(test.top());
       test.pop();
   } 
   
}