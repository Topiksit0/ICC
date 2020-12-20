/* PALOMINO : VIVAR : MARCOS : 47132283Q / NIUB : 20329665 */
/* LOPEZ: RUIZ : GERARD : 46495842P / NIUB : 20274763*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pracFuns.h"


int main(int argc, char const *argv[]){
    double **A, *b;
    int n,i,j;
    double tol;

    printf("Introdueix les dimensions de la matriu");
    scanf("%d", &n);

    while(n < 2){
        printf("Introduce un valor de n valido \n");
        scanf("%d", &n);
    }

    A = (double **) malloc (n * sizeof(double*));
    b = (double *) malloc (n * sizeof(double));

    for(i = 0; i < n; i++){
        A[i] = (double *) malloc(n * sizeof(double));
    }

    printf("\n Introduce los valores de la Matriz A \n");
    
    for(i = 0 ; i < n; i++){
        for(j = 0; j < n; j++){
            printf("A[%d][%d]: ", i, j);
            scanf("%le", &A[i][j]);
        }
    }

    printf("\n Introduce los valroes de el vector B \n");

    for(i = 0; i < n; i++){
        printf("b[%d]", i);
        scanf("%le", &b[i]);
    }

    printf("Escriu la tolerància:\n");
    scanf("%le", &tol);

    gauss(A,b,tol,n);
    printf("\n sistema obtingut al final \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf(" %+10.6lf", A[i][j]);
        }
        printf(" | %+.6lf \n", b[i]);
    }

} 
