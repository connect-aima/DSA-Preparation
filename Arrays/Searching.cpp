#include <iostream>
using namespace std;
int LinearSreach(int arr[],int n,int t){
    for(int i=0;i<n;i++){
        if( arr[i]==t)
            return i;
    }
    return -1;
}
int binarySearch(int arr[], int t, int s, int e) {

    if (s > e) return -1; 

    int mid = s + (e - s) / 2;

    if (t == arr[mid]) {
        return mid;
    } 
    else if (t < arr[mid]) {//search in left half 
        return binarySearch(arr, t, s, mid - 1);
    } 
    else  {//search in right 
        return binarySearch(arr, t, mid + 1, e);
    }
}

int main() {
    
    return 0;
}