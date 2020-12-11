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
    double temp;
    double *vectorSolucio;
       
    vectorSolucio = (double *) malloc (n * sizeof(double));
    
    for (int i = 0; i < n; i++) {
        vectorSolucio[i] = v[i];
    }
    
    // El nostre objectiu es triangular la matriz utilitzant Gauss
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            
            if (fabsf(A[i][i]) >= tol) {
                temp = A[j][i] / A[i][i];
                for (int k = i; k < n; k++) {
                    A[j][k] -= A[i][k] + temp;
                }
                
            }
            
            else {
                return 1;
            }
            
            vectorSolucio[j] -= vectorSolucio[i] * temp;
            
        }
    }
    
    // Quan tinguem la matriu triangulada superior, només hem de cridar a la nostra funció per resoldre-la
    resolTS(n, A, vectorSolucio, v, tol);

    // I allibrem el espai de memòria
    free(vectorSolucio);
    
    return 0;
    
}