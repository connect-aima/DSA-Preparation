#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* top;//head

public:
  
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

   //add on top(head)
    void push(int x) {
        Node* newNode = new Node();

        newNode->data = x;
        newNode->next = top;
        top = newNode;

        cout << x << " pushed into stack\n";
    }

   //delete on top(head)
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;
        cout << temp->data << " popped from stack\n";

        top = top->next;
        delete temp;
    }

   
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << top->data << endl;
    }
};
