#include <iostream>
using namespace std;
class heap{
public:
    int arr[100];
    int size=0;

    void insertion(int val){
        if(size==100){
            cout << "Full" << endl; 
            return;
        }
        size++;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }else{
                return;
            }
        }
    }
    void deletion(){
        if(size==0){
            cout << "Empty" << endl; 
            return; 
        }
        //replace end node with starting node
        arr[1]=arr[size];
        //decrease size
        size--;
        //adjust it using heapify down 
        int i=1;
        while(true){
            int largest=i;
            int left=i*2;
            int right=i*2+1;
            if(left<=size && arr[left]> arr[largest]){
                largest=left;
            }
            if(right<=size && arr[right]>arr[largest]){
                largest=right;
            }
            if(i==largest){
                break;
            }
            swap(arr[i],arr[largest]);
            //after swap current index has the largest value than its child and old value of 
            //current index is now in largest so we have to adjust that , that is why we will make
            //i=largest and it will keep running in while true and will break only if i originally 
            //becomes largest
            i=largest;           
        }
    }

        // printing values
        void print(int arr[],int size)
        {
            for (int i = 1; i <= size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        void heapifyDown(int arr[],int n,int i){
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;
            
            if(left<=n && arr[largest]<arr[left]){
                largest=left;
            }
            if(right<=n && arr[largest]<arr[right]){
                largest=right;
            }
            if(largest!=i){
                swap(arr[largest],arr[i]);
                heapifyDown(arr,n,largest);
            }
        }

        void heapSort(int arr[],int n){
            int size=n;
            while(size>1){
                swap(arr[size],arr[1]); //swap last elemen from first element
                size--; // decrease size
                heapifyDown(arr,size,1);
            }
        }
    
};
int main() {
    heap h;
    int arr[6]={0,5,4,3,2,1};
    int n=5;
    for(int i=n/2;i>0;i--){
        h.heapifyDown(arr,n,i);
    }
    //printing array in which max heap is build 
    h.print(arr,5);
    h.heapSort(arr,5);
    h.print(arr,5);
    return 0;
}