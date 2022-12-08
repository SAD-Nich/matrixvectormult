#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mylib/mylib.h"
void initMat(int* M, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            M[N*i+j] = rand()%10;
        }
    }
}
void initVec(int* v, int N){
    for(int i=0; i<N; i++){
        v[i] = rand()%10;
    }
}
int main(void){
    double run_time = 0.0;
    clock_t start = clock();
    int N = 3;
    int* M = (int *) malloc(N*N*sizeof(int));
    int* v = (int *) malloc(N*sizeof(int));
    int* b = (int *) malloc(N*sizeof(int));
    if(M == NULL | v == NULL){
        printf("Malloc is failed \n");
        exit(0);
    } else {
        initMat(M, N);
        printf("\nM=");
        printMat(M, N);
        initVec(v, N);
        printf("\nv=");
        printVec(v, N);
        matVecMult(M,v,b,N);
        printf("\nb=");
        printVec(b, N);
        printf("\n");
    }
    free(M);
    free(v);
    free(b);
    
    clock_t end = clock();
    run_time += (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total time = %f seconds.", run_time);
    return 0;
}
