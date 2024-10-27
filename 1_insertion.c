#include<stdio.h>
void display(int arr[], int n){
//     Traversal(saare element ko ek baar visit)
    for(int i = 0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int indInsertion(int arr[], int size, int element, int capacity, int index){
    if(size >= capacity){
        return -1;
    }
    for(int i = size; i >= index; i--){
           arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int main() {
    int arr[100] = {7,8,12,27,88};
    int size = 5, element = 45, index = 3;
    display(arr,size);
    indInsertion(arr,size,element,100,index);
    size += 1;
    if(indInsertion(arr,size,element,100,index) == -1){
        printf("Array insertion failed");
    }
    else{
    display(arr,size);
    }
    return 0;
}