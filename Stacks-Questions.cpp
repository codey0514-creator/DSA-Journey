#include <bits/stdc++.h>
using namespace std;
/*
====================================================
NEXT GREATER ELEMENT (MONOTONIC STACK)
====================================================
Problem:
For every element in an array, find the first greater
element on its right.
Example:
arr = {2,1,5,6,1,2,3}
Output:
5 5 6 -1 2 3 -1
----------------------------------------------------
TIME COMPLEXITY
----------------------------------------------------
O(N)
Each element is pushed and popped from the stack
at most once.
----------------------------------------------------
SPACE COMPLEXITY
----------------------------------------------------
O(N)
Stack + Answer Vector
----------------------------------------------------
KEY IDEA
----------------------------------------------------
Traverse from right to left.
While stack top is smaller than current element,
it can never be the answer, so remove it.
The stack always contains potential candidates
for the next greater element.
----------------------------------------------------
NEXT SMALLER ELEMENT
----------------------------------------------------
Replace:
arr[st.top()] < arr[i]
with:
arr[st.top()] > arr[i]
----------------------------------------------------
APPLICATIONS OF MONOTONIC STACK
----------------------------------------------------
1. Next Greater Element I & II
2. Previous Greater Element
3. Next Smaller Element
4. Previous Smaller Element
5. Stock Span
6. Daily Temperatures
7. Largest Rectangle in Histogram
8. Maximal Rectangle
9. Sum of Subarray Minimums
10. Trapping Rain Water
----------------------------------------------------
LARGEST RECTANGLE IN HISTOGRAM
----------------------------------------------------
For each bar:
1. Find Previous Smaller Element (PSE)
2. Find Next Smaller Element (NSE)
Width:
width = nextSmaller - prevSmaller - 1
Area:
area = height * width
This reduces the problem to two monotonic
stack computations.
*/
vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;
    stack<int> st;
    st.push(n - 1);
    ans.push_back(-1);
    for (int i = n - 2; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    vector<int> arr = {2,1,5,6,1,2,3};
    vector<int> ans = nextGreaterElement(arr);
    for (int idx : ans) {
        if (idx == -1)
            cout << -1 << " ";
        else
            cout << arr[idx] << " ";
    }
    return 0;
}