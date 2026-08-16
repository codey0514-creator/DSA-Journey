// STACKS :
// STACK IS ALSO KNOWN AS 
// LAST IN FIRST OUT...
// STACK HAS 3 IMPORTANT FUNCTION :
// 1.) push(val) push a new element to top
// 2.) pop() removes top element
// 3.) top() return top element
// THE BEST PART WITH STACK IS THAT IT DOES ALL THIS IN CONSTANT TIME O(1)
// STACK FROM SCRATCH VIA VECTOR OR ARRAY ( ARRAY IS STATIC)
#include <bits/stdc++.h>
using namespace std;
class Stack{
    vector <int> v;
public :
    void push(int val){
        v.push_back(val);
    }
    void pop(){
        v.pop_back();
    }
    int top(){
        return v[v.size() - 1];
    }
    bool empty(){
        return v.size() == 0;
    }
};
int main(){
   Stack s ;
   s.push(30);
   s.push(20);
   s.push(40);
   stack <int> S; // STACK USING Cpp STL ( VERY IMPORTANT FOR DSA)
   S.push(30);
   S.push(20);
   S.push(40);
   while (! s.empty()){
    cout <<s.top()<< endl;
    cout <<S.top()<< endl;
    S.pop();
    s.pop();
   }
}
