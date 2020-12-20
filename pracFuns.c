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
    double *b;
    int i, k, j;
    double mult;
    
    b = (double *) malloc (n * sizeof(double));
    
    for (i = 0; i < n; i++) {
        b[i] = v[i];
    }
    
    for (k=0; k<n-1; k++) {
        for (i=k+1; i<n; i++) {         
                mult = A[i][k]/A[k][k];             
                for (j=k; j<=n; j++) {
                    A[i][j] = A[i][j]-mult*A[k][j];
                }         
                    
            b[i] -= b[k] * mult;
            
        }
    }
    free(b);
    return resolTS(n, A, b, v, tol);
}
int gausspivot(double **A, double *v, double tol, int n){
    int k, i, j, x;
    double mult, temp, temp2;

    for (k=0; k<n-1; k++) {

        if (pow(fabs(A[k][k]),k) < tol) {
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
            printf(" %+10.6lf", A[i][j]);
        }
        printf(" | %+.6lf \n", v[i]);
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

double spline(int n, double *x, double *M, double *h, double *N, double *L, double z){
    double sum, potencia, potencia2;
    int i;
    for(i = 0 ; i< n-1; i++){
        potencia = x[i+1]-z;
        potencia2 = z- x[i];
        sum = ((M[i]*(pow(potencia,3))/(6*h[i+1]))+(M[i+1]*(pow(potencia2,3))/(6*h[i+1]))+(N[i]*potencia2) + L[i]);
    }
    return sum;
}

double gausstri(double ** A, double * x, double tol, int n){
    int i,j;
    double *a,*b,*c;
    a = (double *) malloc (n * sizeof(double));
    b = (double *) malloc (n * sizeof(double));
    c = (double *) malloc (n * sizeof(double));
    for (i = 1; i < n-1; i++){
        for (j = 0; j < n-1; j++){
        if((j == i-1)){
            a[i-1] = A[i][j];
        }
        else if((j == i)){
            b[i-1] = A[i][j];

        }else if((j == i+1)){
            c[i-1] = A[i][j];


        }
        }
    }
    c[0] = c[0] / b[0];
    x[0] = x[0] / b[0];

    for (i = 1; i < n; n++) {
        float m = 1.0f / (b[i] - a[i] * c[i - 1]);
        if(i < (n-1)) c[i] = c[i] * m;
        x[i] = (x[i] - a[i] * x[i - 1]) * m;
    }

    for (i =  n - 2; i >= 0; --i) {
        x[i] = x[i] - c[i] * x[i + 1];
    }
    return 0;

}