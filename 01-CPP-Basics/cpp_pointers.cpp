// Pointers
// A pointer is a variable that stores the memory address of another variable.
//
// & : Address-of operator
//     Gives the memory address of a variable.
//
// * : Dereference operator
//     Goes to the stored address and accesses the value at that address.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 10;
    // p stores the address of n
    int* p = &n;
    // *p means "go to the address stored in p and give me the value there"
    int a = *p;
    cout << *p << " " << a << endl;     // 10 10
    string FreePizza[5] = {"p1", "p2", "p3", "p4", "p5"};
    // Array names automatically decay into pointers to their first element
    // Therefore FreePizza is equivalent to &FreePizza[0]
    string* pFreePizza = FreePizza;
    // pFreePizza contains the address of the first element ("p1")
    cout << pFreePizza << endl;         // Address of p1
    // Dereferencing gives the value stored at that address
    cout << *pFreePizza << endl;        // p1
    // Pointer arithmetic
    cout << *(pFreePizza + 1) << endl;  // p2
    cout << *(pFreePizza + 2) << endl;  // p3
    cout << *(pFreePizza + 3) << endl;  // p4
    cout << *(pFreePizza + 4) << endl;  // p5
    return 0;
}