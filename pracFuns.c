/* PALOMINO : VIVAR : MARCOS : 47132283Q / NIUB : membre1 de la parella */
/* LOPEZ : RUIZ : GERARD : 46495842P / NIUB : 20274763 */

#include "pracFuns.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int resolTS(int n, double **A, double *b, double *x, double tol){
    int i, j;
    for (i = n - 1; i >= 0; i--){
        x[i] = b[i];     
        if (abs(A[i][i]) < tol){
            return 1;
        }
        else{         
            for (j = n - 1; j > i; j--){
                x[i] -= (A[i][j] * x[j]);                         
            }          
            x[i] /= A[i][i];
        }
    }
    return 0;
}

void prodMatVec(double **A, double *x, double *y, int n){
    int i,j;
    for(i = 0; i < n - 1; i++){
        y[i] = 0;
        for(j = 0; j < n - 1; j++){
            y[i] += A[i][j] * x[j];
        }
    }
}

double norma2(int n, double *z){  
    int i;
    double norma = 0;   
    for (i = 0; i < n - 1; i++){
        norma += pow(z[i], 2);
    }  
    norma = sqrtf(norma);
    return norma;
}

int gauss(double **A, double *v, double tol, int n){
    int i,j,k, x;
    double *t,term;
    t = (double *) malloc (n * sizeof(double));

    for (x = 0; x < n; x++) {
        t[x] = v[x];
    }

    for(i=0;i<n-1;i++){
        for(k=i+1;k<n;k++){
            if (fabsf(A[i][k]) >= tol){
                term=A[k][i]/A[i][i];
                for(j=0;j<n;j++){
                    A[k][j]=A[k][j]-term*A[i][j];
                }
            }
            else{
                return 1;
            }
            t[k] -= t[i] * term;

        }
    }

    resolTS(n,A,t,v,tol);
    free(t);
    return 0;
}
int gausspivot(double **A, double *v, double tol, int n){
    int k, i, j, x;
    double mult, temp, temp2;

    for (k=0; k<n-1; k++) {

        if (fabs(A[k][k]) < tol) {
            for(x = 0; x < n; x++){
                temp = A[k][x];
                A[k][x]= A[k+1][x];
                A[k+1][x] = temp;
            }
            temp2 = v[k];
            v[k] = v[k+1];
            v[k+1] = temp2;
        }

        for (i = k + 1; i < n; i++) {
            mult = A[i][k] / A[k][k];
            A[i][k] = 0.;
            for (j = k+1 ; j <= n; j++) {
                A[i][j] = A[i][j] - mult * A[k][j];
            }
            v[i] = v[i] - mult * v[k];



        }
    }
    printf("\n sistema obtingut al final \n");
    for (i = 0; i < n; i++) {

        for (j = 0; j < n; j++) {
            printf(" %+10.4lf", A[i][j]);
        }
        printf(" | %+.4lf \n", v[i]);
    }
    return 0;

}

double horner(float z , double a [], int grau){
    int i;
    double sum ;
    sum = a [grau];
    for (i = grau; i >= 0; i --){
        sum = sum *z+a[i];
    }
    return sum ;
}