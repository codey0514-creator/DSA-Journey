// In an array, inserting an element at the i-th position requires
// shifting all elements from index i to n-1 by one position.
// Therefore, the time complexity of insertion is O(n).

// To avoid this overhead, we use a Linked List.

// LINKED LIST:
// - Elements are stored in non-contiguous memory locations.
// - Each element is represented by a node.
// - A node consists of:
//     1. Data
//     2. Pointer to the next node

// Thus, nodes are connected through pointers, forming a sequence.
#include <bits/stdc++.h>
using namespace std ;
class Node{
public :
    int data ; 
// Node* ne stores address of ne node; Node ne would recursively embed full nodes.
// C++ requires explicit pointers for linking separate heap objects.
// In Python, node.next automatically stores a reference to the next object (like a hidden pointer), 
//whereas in C++ we must explicitly use Node* next to store and manage the memory address.
    Node * next = nullptr;
    Node(int val){
        data = val ;
        next = nullptr;
    }
};
class LinkedList {
public :
    Node* head ;
    Node* tail ;
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void push_front(int val ){
//We use new in C++ to allocate a Node on the heap so that it 
//continues to exist after the function ends
        Node * ne = new Node(val); // dynamic object
        ne -> next = head;
//We use ne->next = head because ne is a pointer to a node and -> is used to access its members, 
//whereas ne*next = head is invalid syntax and does not mean accessing a member.
        head = ne;
    }
    void push_back(int val){
        Node*ne = new Node(val);
        if (tail == nullptr) {
            head = tail = ne;
        } else {
            tail->next = ne;
            tail = ne;
}
    }
//We delete a node in pop_front() or pop_back() only when we are removing it from the list, 
//because that node was created using new and would otherwise stay in memory forever (memory leak).
    void pop_front(){
        if (head == nullptr)return ;
        Node * ne = head  ;
        head = head -> next ;
        delete ne ;
        if (head == nullptr)
            tail = nullptr;
    }
    void pop_back(){
        Node* current = head;
        if (head == nullptr) return ;
        if (head == tail) {
            Node *temp = head ;
            head = nullptr;
            tail = nullptr;
            delete temp;
            return ;
        }
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    void print(){
        Node * n = head ;
        while (n  != nullptr) {
            cout << n -> data << "\n";
            n = n -> next;
        }
    }
};
int main(){
    LinkedList l1 ;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_front(5);
    l1.print();
    cout << l1.head->data << " "<< l1.tail->data;
    return 0;
}
/*
Cache is a small, very fast memory near the CPU that stores recently used data.
Good cache locality means fewer trips to RAM and faster execution.

Analogy:
Array/Vector = all ingredients are already laid out on the kitchen counter.
Linked List = going to the fridge again and again for each ingredient.

Arrays store elements contiguously, giving excellent cache locality and fewer
cache misses. Linked lists are scattered in memory, causing frequent cache
misses and slower traversal, even though both are O(n).
*/

