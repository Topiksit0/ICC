/* PALOMINO : VIVAR : MARCOS : 47132283Q / NIUB : membre1 de la parella */
/* LOPEZ : RUIZ : GERARD : 46495842P / NIUB : 20274763 */

#include "pracFuns.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int resolTS(int n, double **A, double *b, double *x, double tol){
    for (int i = n - 1; i >= 0; i--){
        x[i] = b[i];     
        if (abs(A[i][i]) < tol){
            return 1;
        }
        else{         
            for (int j = n - 1; j > i; j--){
                x[i] -= (A[i][j] * x[j]);                         
            }          
            x[i] /= A[i][i];
        }
    }
    return 0;
}

void prodMatVec(double **A, double *x, double *y, int n){
    for(int i = 0; i < n - 1; i++){
        y[i] = 0;
        for(int j = 0; j < n - 1; j++){
            y[i] += A[i][j] * x[j];
        }
    }
}

double norma2(int n, double *z){  
    double norma = 0;   
    for (int i = 0; i < n - 1; i++){
        norma += pow(z[i], 2);
    }  
    norma = sqrtf(norma);
    return norma;
}

int gauss(double **A, double *v, double tol, int n){ 
    int i,j,k;
    double *t,term;
    t = (double *) malloc (n * sizeof(double));

    for (int x = 0; x < n; x++) {
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