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
    //Deletion
    void deletionAtHead(){
        if(head==nullptr){
            cout << "empty" <<endl;
        }else{
           Node* del=head;
           head=head->next;
           delete del;
        }
    }
    void deletionAtPosition(int pos){
         if(pos<0){
            cout << " invalid pos " <<endl;
            return;
        }
        if(head==nullptr){
            cout << " Empty " <<endl;
            return;
        }
        if(pos==0){
            deletionAtHead();
            return;
        }
        Node* temp=head;
        int currPos=0;
        while(currPos<pos-1&&temp->next!=nullptr){
            temp=temp->next;
            currPos++;
        }
        if(temp->next==nullptr){
            cout << "out of bond" <<endl;
            return;
        }
       Node* del=temp->next;
       temp->next=temp->next->next;
       delete del;
    }
    void deletionAtTail(){
        if(head==nullptr){
            return;
        }else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }else{
            Node* temp=head;
            //stop temp at second last node
            while(temp->next->next!=nullptr){
                temp=temp->next;
            }
            Node* toDelete = temp->next; 
            temp->next = nullptr;      
            delete toDelete;   
        }
    }
     void searchAndUpdate(int org, int val)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == org)
                break;
            temp = temp->next;
        }
        temp->data = val;
        cout << "value is updated!" << endl;
    }
    void splitList()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *slow = head;
        Node *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *head2 = slow->next;
        slow->next = nullptr;
        display(head);
        display(head2);
    }
    void bubbleSort(){
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
    //reversing list using recursion
     Node *reverseLinkedListRecursion(Node *&head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *newHead = reverseLinkedListRecursion(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
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
        return head1;
    }
    void deleteOdd(Node *&head)
    {
        Node *curr = head;
        while (curr != NULL && curr->next != NULL)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete (temp);
            curr = curr->next;
        }
    }
    // deleting dublicates in linked list
    void deleteDublicates(Node *head)
    {
        Node *curr = head;
        while (curr != NULL && curr->next != NULL)
        {
            Node *temp = curr->next;
            if (curr->data == temp->data)
            {
                curr->next = curr->next->next;
                delete (temp);
            }
            else
            {
                curr = curr->next;
            }
        }
    }
    // display
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
    void display(Node* head){
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
    sll.inserAtHead(55);
    sll.inserAtHead(56);
    sll.insertAtTail(3);
    sll.insertAtPosition(2,100);
    sll.display();
    sll.bubbleSort();
    sll.display();
    return 0;
}