/* PALOMINO : VIVAR : MARCOS : 47132283Q / NIUB : membre1 de la parella */
/* COGNOM1 : COGNOM2 : NOM : DNI / NIUB : membre2 de la parella */

#include "pracFuns.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int resolTS (int n, double **A, double *b, double *x, double tol){
    for(int i = n-1; i >= 0; i--){
        x[i] = b[i];  
        if(abs(A[i][i]) < tol){
            return 1;
        }
        else{
            for(int j = n-1; j > i; j--){
                 
            }
        }
    }
}

void prodMatVec (double **A, double *x, double *y, int n){

}

double norma2 (int n, double *z){


}