#include<stdio.h>
void printArray(int*A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void selectionsort(int*A,int n){
    int indexofMin,temp;
    for(int i =0; i< n-1; i++){
        indexofMin = i;
        for(int j = i + 1; j < n; j++){
            if(A[j] < A[indexofMin]){
                indexofMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i]=A[indexofMin];
        A[indexofMin] = temp;
    }
}
int main(){
    int A[]= {53,68,43,90,67,11,22,2};
    int n = 8;
    printArray(A,n);
    selectionsort(A,n);
    printArray(A,n);
    return 0;
}