#include<stdio.h>

void printArray(int*A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void insertsort(int*A, int n){
    // loop for passes
    int key,j;
    for(int i = 1; i <= n-1; i++){
        // loop for each pass
        key = A[i];
        j = i -1;
        while(j>=0 && A[j]>key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }

}
int main(){
    int A[]= {53,68,43,90,67,11,22,2};
    int n = 8;
    printArray(A,n);
    insertsort(A,n);
    printArray(A,n);
    return 0;
}