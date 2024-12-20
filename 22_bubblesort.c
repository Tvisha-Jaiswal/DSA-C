#include <stdio.h>
void printArray(int*A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void bubblesort(int*A,int n){
    int isSorted = 0;
    for(int i =0; i < n-1; i++){ //for number of pass
        printf("Working on pass no. %d\n",i);
        isSorted = 1;
        for(int j = 0; j < n-i-1; j++){ //for numper of comparison
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
  
}
int main(){
    int A[]= {53,68,43,90,67,11,22,2};
    // int A[] = {1,2,3,4,5,6,7,8};
    int n = 8;
    printArray(A,n);
    bubblesort(A,n);
    printArray(A,n);
    return 0;
}