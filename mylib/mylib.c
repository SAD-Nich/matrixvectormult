
#include <stdio.h>
#include <stdlib.h>


void printMat(int* M, int N){

    printf("[");
    for(int i=0; i<N; i++){
        printf("\n");
        for(int j=0; j<N; j++){
            printf("%d,\t",M[N*i+j]);
        }
    }
    printf("]\n");

}

void printVec(int* v, int N){
    printf("[");
    for(int i=0; i<N; i++){
        printf("\n");
        printf("%d,\t",v[i]);
    }
    printf("]\n");
}


void matVecMult(int* M, int* v, int* result, int N){

    for(int i=0; i<N; i++){
        result[i]=0;
        for(int j=0; j<N; j++){
            result[i] += M[N*i+j]*v[j];
        }
    }

}


#define LOWER 1
#define UPPER 9

int generateRandomInt(int lower, int upper){
    return (rand() % (upper-lower+1)) + lower;
}

void initMat(int* M, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            M[N*i+j] = generateRandomInt(LOWER,UPPER);
        }
    }
}

void initVec(int* v, int N){
    for(int i=0; i<N; i++){
        v[i] = generateRandomInt(LOWER,UPPER);
    }
}