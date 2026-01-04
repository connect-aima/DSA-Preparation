#include <iostream>
using namespace std;
#include <climits>
//non primitive pass by refrence

//Linear Search algorithm
int LinearSreach(int arr[],int n,int t){
    for(int i=0;i<n;i++){
        if( arr[i]==t)
            return i;
    }
    return -1;
}
//reverse array using two pointer approach
void reverseArray(int arr[],int n){
    int s=0;
    int e=n-1;
    while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }   
}        
int main() {
    // //initializing array
    // int arr [5];
    // int size1=sizeof(arr)/sizeof(arr[0]);
    // //talking input in array
    // for(int i=0;i<size1;i++){
    //     cin >> arr[i];
    // }
    int arr1[]={11,12,13};
    //size of any array
    int size2=sizeof(arr1)/sizeof(arr1[0]);
    reverseArray(arr1,size2);
    //traversing on array
    for(int i=0;i<size2;i++){
        cout << arr1[i] << " ";
    }
    cout <<endl;
    //finding smalles and largest in array
    // int smallest = INT_MAX;
    // int largest=INT_MIN;
    // int sum=0;
    //  for(int i=0;i<size2;i++){
    //     if(arr1[i]<smallest)
    //     smallest=arr1[i];
    //     largest=max(arr1[i],largest);
    //     sum+=arr1[i];
    // }
    // cout<< " Smallest " << smallest <<" Largest " << largest  << " Sum " <<sum<<endl;
    return 0;
}