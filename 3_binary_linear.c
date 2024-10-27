#include <stdio.h>

int linearSearch(int arr[], int size, int element){
    for(int i = 0; i < size; i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[], int size, int element){
    int mid, high, low;
    low = 0;
    high = size-1;
    
    while(low<=high){
    mid = (low + high)/2;
    if(arr[mid] == element){
        return mid;
    }
    else if(arr[mid] < element){
        low = mid + 1;
    }
    else if( element < arr[mid]){
        high = mid - 1;
    }
    }
    return -1;
}
int main() {
    // unsorted array for linear search
    int arr[] = {1,3,5,56,4,23,54643,53,34};
    // sorted array for binary search
    int arr2[] = {1,3,4,5,23,34,53,56,54643};
    int element = 28;
    int element2 = 53;
    int size = sizeof(arr)/sizeof(int);
    int size2 = sizeof(arr2)/sizeof(int);
    int searchIndex = linearSearch(arr,size, element);
    int searchIndex2 = binarySearch(arr2,size2, element2);
    printf("The element %d was found at %d index \n", element, searchIndex);
    printf("The element %d was found at %d index \n", element2, searchIndex2);
    return 0;
}