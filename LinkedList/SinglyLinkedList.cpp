#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next=nullptr;
    }
};
class SinglyLinkedList{
public:
    Node* head;
    SinglyLinkedList(){
        head=nullptr;
    }
    //insertion 
    void inserAtHead(int data){
        Node* newNode=new Node(data);
        newNode->next=head;
        head=newNode;    
    }
    void insertAtPosition(int pos , int val){
        if(pos<0){
            cout << " invalid pos " <<endl;
            return;
        }
        if(pos==0){
            inserAtHead(val);
            return;
        }
        Node* newNode=new Node(val);
        Node* temp=head;
        int currPos=0;
        while(currPos<pos-1&&temp->next!=nullptr){
            temp=temp->next;
            currPos++;
        }
        if(currPos!=pos-1){
            cout << "out of bond" <<endl;
            return;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    void insertAtTail(int val){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=newNode;
            return;
        }else{
            Node* temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    void display(){
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp=head;
        while (temp!=nullptr)
        {
            cout << temp->data << "->" ;
            temp=temp->next;
        }
        cout << "null" << endl;       
    }
};

int main() {
    SinglyLinkedList sll;
    sll.inserAtHead(0);
    sll.inserAtHead(-1);
    sll.insertAtTail(3);
    sll.insertAtPosition(2,2);
    sll.display();
    return 0;
}