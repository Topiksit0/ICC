/* PALOMINO : VIVAR : MARCOS : 47132283Q / NIUB : membre1 de la parella */
/* COGNOM1 : COGNOM2 : NOM : DNI / NIUB : membre2 de la parella */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pracFuns.h"

int main(int argc, char *argv[]) {
    double **A, *b, *x;
    int n;

    printf("Introdueix les dimensions de la matriu");
    scanf("%d", &n);

    while(n < 2){
        printf("Introduce un valor de n valido \n");
        scanf("%d", &n);
    }

    A = (double **) malloc (n * sizeof(double*));
    b = (double *) malloc (n * sizeof(double));
    x = (double *) malloc (n * sizeof(double));

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

    printf("\n Vector soluci0 x = \n");
    resolTS(n,A,b,x,0.001);
    for (int i = 0; i < n; i++){
        printf( "%16.7e ", x[i]);
    }

    printf(" \n El valor de z és: \n");
    double z = norma2(n, x);
    printf("%d", &z);

    return 0;
    
}

