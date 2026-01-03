#include <iostream>
using namespace std;

class StaticQueue {
    int* arr;       
    int cap;   
    int f; 
    int r; 
    int currSize;

public:
    StaticQueue(int size) {
        cap = size;
        arr = new int[cap];
        f = 0;
        r = -1; 
        currSize=0;
    }

    bool empty() {
        return currSize==0;
    }

    bool full() {
        return currSize==cap;
    }

    // add at rear
    void enqueue(int val) {
        if(full()) {
            cout << "Queue is full\n";
            return;
        }
        r++;
        arr[r] = val;
        currSize++;
    }

    // remove from front
    void dequeue() {
        if(empty()) {
            cout << "Queue is empty\n";
            return;
        }
        f++;
        currSize--;
    }

    
    void front() {
        if(empty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front: " << arr[f] << endl;
    }

    // display all elements
   void display() {
    if(empty()) {
        cout << "Queue is empty\n";
        return;
    }
    for(int i = f; i <= r; i++) { // simpler
        cout << arr[i] << " ";
    }
    cout << endl;
}
};
class CircularQueue{
   int* arr;
   int cap;
   int f;
   int r;
   int currSize;
public:
   CircularQueue(int size){
    cap=size;
    arr=new int [cap];
    f=0;
    r=-1;
    currSize=0;
   }
   void enqueue(int data){
        if(isFull()){
            return;
        }
        r=(r+1)%cap;
        arr[r]=data;
        currSize++;
   }
   void dequeue(int data){
        if(isEmpty){
            return;
        }
        f=(f+1)%cap;
        currSize--;
   }
   void front(){
        if(isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << arr[f] << endl;
   }
   bool isFull(){
    return currSize==cap;
   }
   bool isEmpty(){
    return currSize==0;
   }
   void display() {
    if(isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    int i = f;
    while(true) {
        cout << arr[i] << " ";
        if(i == r) break;      // stop when we reach rear
        i = (i + 1) % cap;     // circular increment
    }
    cout << endl;
}
};
class DoubleEndedQueue{
    int* arr;       
    int cap;   
    int f; 
    int r; 
    int currSize;

public:
    DoubleEndedQueue(int size) {
        cap = size;
        arr = new int[cap];
        f = 0;
        r = -1; 
        currSize=0;
    }

    bool empty() {
        return currSize==0;
    }

    bool full() {
        return currSize==cap;
    }

    // add at rear
    void enqueueEnd(int val) {
        if(full()) {
            cout << "Queue is full\n";
            return;
        }
        r++;
        arr[r] = val;
        currSize++;
    }
    void enqueueStart(int val){
        if(full()) {
            cout << "Queue is full\n";
            return;
        }
        for(int i=r;i>=f;i--){
            arr[i+1]=arr[i];//right shift
        }
        arr[f]=val;
        r++;
        currSize++;
    }

    // remove from front
    void dequeueStart() {
        if(empty()) {
            cout << "Queue is empty\n";
            return;
        }
        f++;
        currSize--;
        if(currSize == 0) { 
            f = 0;
            r = -1;
        }
    }

    void dequeueEnd(){
        if(empty()) {
            cout << "Queue is empty\n";
            return;
        }
        r--;
        currSize--;
         if(currSize == 0) { // reset indices
            f = 0;
            r = -1;
        }
    }

    
    void front() {
        if(empty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front: " << arr[f] << endl;
    }

    // display all elements
   void display() {
    if(empty()) {
        cout << "Queue is empty\n";
        return;
    }
    for(int i = f; i <= r; i++) { // simpler
        cout << arr[i] << " ";
    }
    cout << endl;
}
};
class PriorityQueue{
public:
    int* arr;
    int* prio;
    int cap;
    int currSize;
    PriorityQueue(int size){
        cap=size;
        arr=new int[cap];
        prio=new int[cap];
    }
    void enqueue(int v,int p){
        if(full()){
            return;
        }
        int i = currSize - 1; // start from last element
        while (i >= 0 && prio[i] > p) { // fixed: maintain ascending order by priority
            arr[i + 1] = arr[i];
            prio[i + 1] = prio[i];
            i--;
        }

        arr[i + 1] = v;
        prio[i + 1] = p;
        currSize++;
        cout << "Inserted (" << v << ", priority: " << p << ") in static PQ\n";
    }
    void dequeue(){
      if(empty()) {
        cout << "Queue Empty!\n";
        return;
    }

    cout << "Dequeuing top priority element: " << arr[0] 
         << " (priority: " << prio[0] << ")\n";

    // shift everything left
    for(int i = 0; i <currSize-1 ; i++) //looping till second last index
    {
        arr[i] = arr[i + 1];
        prio[i] = prio[i + 1];
    }
    currSize--;
    }
     bool empty() {
        return currSize==0;
    }

    bool full() {
        return currSize==cap;
    }
    void display() {
        if(empty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Priority Queue: \n";
        for(int i = 0; i < currSize; i++) {
            cout << "(" << arr[i] << ", priority: " << prio[i] << ") ";
        }
        cout << endl;
    }
};
int main() {
    
    return 0;
}