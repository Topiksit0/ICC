/* PALOMINO : VIVAR : MARCOS : 47132283Q / NIUB : membre1 de la parella */
/* LOPEZ: RUIZ : GERARD : 46495842P / NIUB : 20274763*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pracFuns.h"


int main(int argc, char const *argv[]){
    double **A, *b;
    int n;

    printf("Introdueix les dimensions de la matriu");
    scanf("%d", &n);

    while(n < 2){
        printf("Introduce un valor de n valido \n");
        scanf("%d", &n);
    }

    A = (double **) malloc (n * sizeof(double*));
    b = (double *) malloc (n * sizeof(double));

    for(int i = 0; i < n; i++){
        A[i] = (double *) malloc(n * sizeof(double));
    }

    printf("\n Introduce los valores de la Matriz A \n");
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("A[%d][%d]: ", i, j);
            scanf("%le", &A[i][j]);
        }
    }

    printf("\n Introduce los valroes de el vector B \n");

    for(int i = 0; i < n; i++){
        printf("b[%d]", i);
        scanf("%le", &b[i]);
    }

    printf("\n Vector soluci0 b = \n");
    gauss(A,b,0.001,n);
    for (int i = 0; i < n; i++){
        printf( "%lf ", b[i]);
    }
} 
