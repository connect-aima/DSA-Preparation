#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
 class CircularLinkedList{
    Node* head;
    Node* tail;
    public:
    CircularLinkedList(){
        head=tail=nullptr;
    }
    //insertion at head
        void insertAthead(int val){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=tail=newNode;
            tail->next=head;
        }else{
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
    }

        void insertAtTail(int val){
         Node* newNode=new Node(val);
        if(head==nullptr){
            head=tail=newNode;
            tail->next=head;
        }else{
            newNode->next=head;
            tail->next=newNode;
            tail=newNode;
        }
    }
    
        int getLength(){
        if(head == nullptr && tail == nullptr){
            return 0;
        }else{
            int count=0;
            Node* temp=head;
           do{
                count++;
                temp=temp->next;
            } while(temp!=head);
            return count;
        }
    }

        void insertAtPosition(int pos,int val){
        int count=getLength();
        if(pos<0||pos>count){
            cout << "Ahh out of bond" << endl;
            return;
        }
        if (pos==0){
            insertAthead(val);
        }else{
            Node* newNode=new Node(val);
            Node* temp=head;
            int curr=0;
            while(curr!=pos-1){
                temp=temp->next;
                curr++;
            }
            newNode->next=temp->next;
            temp->next=newNode;
            if (temp == tail) {  
            tail = newNode;  
            }

        }
    }
        
        void deleteHead (){
         if(head == nullptr && tail == nullptr){
            cout << "List is empty" << endl;
            return;
         }
         if(head==tail){
            delete head;
            head=tail=nullptr;
            return;
         }else{
            Node* del=head;
            head=head->next;
            tail->next=head;
            delete del;
         }
    }
        
        void deleteAtTail(){
         if(head == nullptr && tail == nullptr){
            cout << "List is empty" << endl;
            return;
         }
         if(head==tail){
            delete head;
            head=tail=nullptr;
            return;
         }else{
            Node* temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            Node* del=tail;
            tail=temp;
            tail->next=head;
            delete del;
         }
    }

        void deleteAtPosition(int pos){
        int count=getLength();
        if(pos<0||pos>count){
            cout << "Ahh out of bond" << endl;
            return;
        }
        if (pos==0){
            deleteHead();
            return;
        }else{
            Node* temp=head;
            int curr=0;
            while(curr!=pos-1){
                temp=temp->next;
                curr++;
            }
            Node* del=temp->next;
            temp->next=temp->next->next;
            if (del == tail) {
                tail = temp;      
            }
            delete del;
    }
}
        
        void search (int val){
    if (head == NULL) {   // case: empty list
        cout << "The list is empty" << endl;
        return;
    }
    bool found=false;
    Node* temp=head;
    int index=0;
    do{
        if(temp->data==val){
            cout<< "your value is found at index " << index << endl;
            found=true;
            break;
        }
        temp=temp->next;
        index++;
    }while(temp!=head);
    if(found==false){
        cout << "The value you are looking for is not in linked list";
    }
}

        void update(int index,int val){
    int len=getLength();
    if (head == NULL) {   
        cout << "The list is empty" << endl;
        return;
    }
     if(index<0||index>=len){
            cout << "Ahh out of bond" << endl;
            return;
        }else{
            
            Node* temp=head;
            int curr=0;
            while(curr!=index){
                temp=temp->next;
                curr++;
            }
            temp->data=val;
            cout << "update succesfull" << endl;
        }
        }
   
        void sort(){
         if (head == NULL) {   
        cout << "The list is empty" << endl;
        return;
    }
     if (head->next==head) {   
        cout << "list had one node so already sorted" << endl;
        return;
    }
    
        Node* curr=head;
      
        do{
            Node* index=curr->next;
            while(index!=head){
            if(curr->data>index->data){
                int temp=curr->data;
                curr->data=index->data;
                index->data=temp;
            }
            index=index->next;
            }
            curr=curr->next;
        }while(curr->next!=head);
    }

void sort(Node* &head){
         if (head == NULL) {   
        cout << "The list is empty" << endl;
        return;
    }
     if (head->next==head) {   
        cout << "list had one node so already sorted" << endl;
        return;
    }
    
        Node* curr=head;
      
        do{
            Node* index=curr->next;
            while(index!=head){
            if(curr->data>index->data){
                int temp=curr->data;
                curr->data=index->data;
                index->data=temp;
            }
            index=index->next;
            }
            curr=curr->next;
        }while(curr->next!=head);
    }


        void split(){
        if (head == NULL) {   
        cout << "The list is empty" << endl;
        return;
        }
        if (head->next==head) {   
        cout << "list had one node so already splitted and sorted" << endl;
        return;
        }
           Node* head2;
           Node* slow=head;
           Node* fast=slow->next;
           while(fast!=head && fast->next!=head){
            slow=slow->next;
            fast=fast->next->next;
           }
          head2=slow->next;
          slow->next=head;
          fast->next=head2;
        sort(head);
        display(head);
        sort(head2);
        display(head2);
    }
    //displaying circular linked list
    void display(){
    if (head == nullptr)
        return;
        
    Node* temp = head;

    do {
        cout << temp->data << "-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "Head" << endl;
}

    void display(Node* &head){
    if (head == nullptr)
        return;
        
    Node* temp = head;

    do {
        cout << temp->data << "-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "Head" << endl;
}
};





int main()
{
    CircularLinkedList cll;
    cll.insertAthead(33);
    cll.insertAthead(22);
    cll.insertAthead(11);
    cll.insertAtTail(14);
    cll.insertAtTail(55);
    cll.insertAthead(24);
    cll.display();
    cll.split();
    
   
    return 0;
}