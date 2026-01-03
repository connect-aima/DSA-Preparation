#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=nullptr;
    }

};
//we add from rear(end) and remove from front(start) fifo
class NormalQueue{
public:
    Node* head;
    Node* tail;
    NormalQueue(){
        head=tail=nullptr;
    }
    // we add from rear end (tail)
    void enqueue(int val){
        Node* newNode=new Node(val);
        if(empty()){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    //we remove from front (delete at head)
    void dequeue(){
        if(empty()){
            return;
        }
        Node* del=head;//mark head
        head=head->next;//move head
        delete del;// delete old head
        if(head==nullptr){ // update tail
            tail=nullptr;
        }
    }
    bool empty(){
        return head==nullptr;
    }
    void front(){
        if(empty()){
            return;
        }
        cout << head->data << endl;
    }
    void display(){
        if(empty()){
            return;
        }
        Node* temp=head;
        while(temp!=nullptr){
            cout << temp->data << "->" ;
            temp=temp->next;
        }
        cout << "null" << endl ;
    }
};
//we can add and remove from both ends
class DoubleEndedQueue{
    public:
    Node* head;
    Node* tail;
    DoubleEndedQueue(){
        head=tail=nullptr;
    }
    // we can add from rear end (tail)
    void enqueueFromTail(int val){
        Node* newNode=new Node(val);
        if(empty()){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    // we can add from front end (head)
    void enqueueFromHead(int val){
        Node* newNode=new Node(val);
        if(empty()){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
    //we can remove from front (delete at head) 
    void dequeueFromHead(){
        if(empty()){
            return;
        }
        Node* del=head;//mark head
        head=head->next;//move head
        delete del;// delete old head
        if(head==nullptr){ // update tail
            tail=nullptr;
        }
    }
    //we can remove from tail (delete at tail) 
    void dequeueFromTail(){
        if(empty()){
            return;
        }
        if(head == tail){ // only one node
        delete head;
        head=tail=nullptr; 
        return;
    }
        Node* temp=head;
        //stop temp at second last node
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        Node* del=temp->next;//mark next of temp
        temp->next=nullptr;
        delete del;
        tail=temp;//update tail
    }
    bool empty(){
        return head==nullptr;
    }
    void front(){
        if(empty()){
            return;
        }
        cout << head->data << endl;
    }
    void display(){
        if(empty()){
            return;
        }
        Node* temp=head;
        while(temp!=nullptr){
            cout << temp->data << "->" ;
            temp=temp->next;
        }
        cout << "null" << endl ;
    }
};
//data gets store in circular manner
class CircularQueue{
    public:
    Node* head;
    Node* tail;
    CircularQueue(){
        head=tail=nullptr;
    }
    // we add from rear end (tail)
    void enqueue(int val){
        Node* newNode=new Node(val);
        if(empty()){
            head=tail=newNode;
            tail->next=head;
        }else{
            tail->next=newNode;
            tail=newNode;
            tail->next=head;
        }
    }
    //we remove from front (delete at head)
    void dequeue(){
    if(empty()) return;

    if(head == tail){ // only one node
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* del = head;
    head = head->next;
    delete del;
    tail->next = head;
    }
    bool empty(){
        return head==nullptr;
    }
    void front(){
        if(empty()){
            return;
        }
        cout << head->data << endl;
    }
    void display(){
        if(empty()){
            return;
        }
        Node* temp = head;
    do{
        cout << temp->data << "->";
        temp = temp->next;
    } while(temp != head); // stop at head again
    cout << "(head)" << endl; // indicate circular
    }
};
//data get store with decided prority
class Node2 {
public:
    int data;
    int priority;
    Node2* next;
    Node2(int val, int prio) {
        data = val;
        priority = prio;
        next = nullptr;
    }
};

class PriorityQueue {
    Node2* head; // front = highest priority
public:
    PriorityQueue() {
        head = nullptr;
    }

    bool empty() {
        return head == nullptr;
    }

    // insert based on priority (higher priority comes first)
    void enqueue(int val, int prio) {
        Node2* newNode = new Node2(val, prio);
        if(empty() || prio > head->priority) { // insert at front
            newNode->next = head;
            head = newNode;
            return;
        }

        Node2* temp = head;
        while(temp->next != nullptr && temp->next->priority >= prio) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // remove highest priority element
    void remove() {
        if(empty()) return;
        Node2* del = head;
        head = head->next;
        delete del;
    }

    // view front element
    void front() {
        if(empty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Data: " << head->data << ", Priority: " << head->priority << endl;
    }

    // display all elements
    void display() {
        if(empty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node2* temp = head;
        while(temp != nullptr) {
            cout << "(" << temp->data << "," << temp->priority << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    NormalQueue nq;
    nq.enqueue(1);
    nq.enqueue(2);
    nq.enqueue(3);
    nq.display();
    nq.dequeue();
    nq.front();
    return 0;
}