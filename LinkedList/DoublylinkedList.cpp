#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data=data;
        prev=next=nullptr;
    }
};
class DoublyLinkedList{
public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head=tail=nullptr;
    }
    void insertionAtHead(int val){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=tail=newNode;
            return;
        }
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }
    void insertionAtTail(int val){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
    void insertionAtPosition(int pos,int val){
        if(pos<0){
            cout << "Invalid Position" << endl;
            return;
        }
        if(pos==0 ){
            insertionAtHead(val);
            return;
        }
        if(head==nullptr){
            cout << "Empty" << endl;
            return;
        }
        Node* temp=head;
        int currPos=0;
        while(currPos<pos-1&&temp->next!=nullptr){
            temp=temp->next;
            currPos++;
        }
        if(currPos!=pos-1){
            cout << "Out of bond" <<endl;
            return;
        }
        Node* newNode=new Node(val);
        newNode->next=temp->next;
        newNode->prev=temp;
        if(temp->next!=nullptr){
            temp->next->prev=newNode;
        }else{
            tail=newNode;
        }
        temp->next=newNode;
    }
   void deletionAtHead() {
    if (head == nullptr) return;      
    Node* del = head;                 

    if (head->next == nullptr) {      
        head = tail = nullptr;        
    } else {
        head = head->next;             
        head->prev = nullptr;          
    }
    delete del;                        
    }
    void deletionAtPosition(int pos){
        if(pos<0){
            cout << "Invalid" ; 
            return;
        }
        if(head==nullptr){
            cout << "Empty" ;
            return;
        }
        if(pos==0){
           deletionAtHead();
            return; 
        }
        if(head==tail){
            deletionAtHead();
            return;
        }
        Node* temp=head;
        int currPos=0;
        while(currPos<pos-1 && temp->next!=nullptr){
            temp=temp->next;
            currPos++;
        }
        if(temp->next==nullptr){
            cout << "Invalid Pos" ;
            return;
        }
        Node* del=temp->next;
        temp->next=del->next;//forward link same in both cases(middle /end node)
        if(del->next!=nullptr){//if delete is on middle node somewhere
            del->next->prev=temp;
        }else{
            tail=temp;//else update tail
        }
        //actual deleting logic
        del->next=nullptr;
        del->prev=nullptr;
        delete del;     
    }
    void deleteAtTail(){
         if(head==nullptr){//empty
            cout << "Empty" ;
            return;
        }
        if(head==tail){//single node
            deletionAtHead();
            return;
        }
        Node* del=tail;//marking old tail
        tail=tail->prev;//updating tail
        tail->next=nullptr;//ensuring next of current tail is null
        delete del;
    }
    Node* reverse(Node* &head){
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        Node* newHead=reverse(head->next);
        head->next->next = head;
        head->prev = head->next;
        head->next = nullptr;
        head->prev = nullptr;
        return newHead;
    }
    void split(){
        if(head==nullptr||head->next==nullptr){
            return ;
        }
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow will be pointing at mid after while loop
        Node* newHead=slow->next;
        slow->next=nullptr;//assigning null to forward link of first half 
        newHead->prev=nullptr;//assigning null to backword link of second half 
        display(head);
        display(newHead);
    }
    void sort(){
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node* i=head;
        while(i->next!=nullptr){//outer loop second last node
            Node* j=i->next;
            while(j!=nullptr){ //inner loop till end
                if(i->data>j->data){
                    int temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                }
                j=j->next;
            }
            i=i->next;
        }
    }
    Node *mergeLinkedList(Node *&head1, Node *&head2)
    {
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;
        Node *temp = head1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head2;
        head2->prev=temp;
        return head1;
    }
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void display(Node* head)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    DoublyLinkedList dll;
    dll.insertionAtHead(0);
    dll.insertionAtHead(12);
    dll.insertionAtPosition(1,13);
    dll.insertionAtPosition(1,15);
    dll.display();
    dll.deleteAtTail();
    dll.deletionAtHead();
    dll.deletionAtPosition(1);
    dll.display();
    return 0;
}