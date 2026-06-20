#include <bits/stdc++.h>
using namespace std;
//QUEUE :- 
// It is known as First in First out (FIFO) Data Structure 
// It has 3 important functions :
// 1.) Push :- It pushes element to last index (ENQUEUE)
// 2.) Pop :- It removes element from the first  (DEQUEUE)
// 3.) Front :- It gives data of the element in the front (first element)
// ALL THESE OPERATIONS HAPPENS IN O(1) TIME COMPLEXITY
// First we will implement Queue using Linked List :
class Node {
public :
    int data ;
    Node * next = nullptr ;
    Node(int val){
        data = val ;
    }
};
class Queue{
    Node*head = nullptr ;
    Node*tail = nullptr ;
public :
    void enqueue(int val){       //PUSH
        Node * ne = new Node(val);
        if (head == tail && tail == nullptr) head = tail = ne ;
        else tail->next =ne;
        tail = ne ;
    }
    void dequeue(){              //POP
        if (head != nullptr){
        Node * ne = head ;
        head = head-> next ;
        delete ne ;
        }
    }
    int front() {               
        if (head == nullptr) return -1 ;
        return head->data;
    }
    bool empty(){
        return head == nullptr ;
    }
};
int main(){
    Queue Q ;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    while (!Q.empty() ){
        cout << Q.front() << "\n";
        Q.dequeue();
    }
    //Now we will implement it using Cpp STL (Standard Template Library)
    queue<int> q ; //TO USE THIS WE DO #include <queue>
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty() ){
        cout << q.front() << "\n";
        q.pop();
    }
    //We have another Data structure known as Deque (Double Ended Queue)
    deque<int>dq ;   //TO USE THIS WE DO #include <deque>
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    // 1 , 2 ,3 
    dq.push_front(4);
    // 4 , 1 , 2 ,3 
    cout << dq.front()<< " " << dq.back() << endl;
    dq.pop_back();
    cout << dq.front()<< " " << dq.back() << endl;
    return 0;
}
