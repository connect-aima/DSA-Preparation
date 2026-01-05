#include <iostream>
using namespace std;

class Stack {
private:
    int arr[5];     
    int top;

public:
   
    Stack() {
        top = -1;   
    }

   
    bool isEmpty() {
        return top == -1;
    }

   
    bool isFull() {
        return top == 4;   
    }

    
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = x;
        cout << x << " pushed into stack\n";
    }

   
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top] << " popped from stack\n";
        top--;
    }

    // extra helper (not counted)
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }
};
