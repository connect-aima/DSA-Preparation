//merge insertion bubble i am wrting logic for accending sorts
#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(int arr[],int n){//O(n*n)
    for(int i=0;i<n-1;i++){
        bool isSwap=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
        }
        if(!isSwap){
            return;
        }
    }
}
void insertionSort(int arr[],int n){//O(n*n)
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
}
//helper function of merge sort
void merge(int arr[],int s,int mid,int e){//O(logn)
    vector<int> temp;
    int i=s;
    int j=mid+1;
    while(i<=mid&&j<=e){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){//remaining of left
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=e){//remaining of right
        temp.push_back(arr[j]);
        j++;
    }
    //coping element from temp into orignal arr
    for(int k=0;k<temp.size();k++){
        arr[k+s]=temp[k];
    }
}
void mergeSort(int arr[],int s,int e){
    if(s<e){
        int mid=s+(e-s)/2;
        mergeSort(arr, s, mid);//leftHalf
        mergeSort(arr,mid+1,e);//right half
        merge(arr,s,mid,e);
    }
}
void SlectionSort(int arr[],int n){//O(n*n)
    for(int i=0;i<n-1;i++){
        int smallest=i;
        for (int j=i+1;j<n;j++){
            if(arr[j]<arr[smallest]){
                smallest=j;
            }
        }
        swap(arr[i],arr[smallest]);
    }
}
int main() {
    int arr[]={3,5,1,2,8};
    int size=5;
    // bubbleSort(arr,size);
    // SlectionSort(arr,size);
    // insertionSort(arr,size);
    int s=0;
    int e=size-1;
    mergeSort(arr,s,e);
     //traversing on array
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    return 0;
}