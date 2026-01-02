#include <iostream>
using namespace std;
//insertion deletion
int main() {
    //insertion
    // int arr[6]={1,2,3,4,6};
    // int cap=6;
    // int size=5;
    // int pos= 2;
    // int t=5;
    // for (int i = size; i > pos; i--) {
    //     arr[i] = arr[i - 1];//right shift
    // }
    // arr[pos] = t;
    // size++;
//deletion
    int arr [5] = {1,2,3,4,5};
    int size=5;
    int pos=3;
    for (int i = pos; i < size - 1; i++) {
    arr[i] = arr[i + 1];//left shift
    }
    size--;
     //traversing on array
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    return 0;
}