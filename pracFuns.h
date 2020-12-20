/* PALOMINO : VIVAR : MARCOS : 47132283Q / NIUB : membre1 de la parella */
/* LOPEZ : RUIZ : GERARD : 46495842P / NIUB : 20274763 */

#include <stdio.h>
#include <math.h>



void prodMatVec (double ** A, double * x, double * y, int n);
double norma2(int n, double * z);
int resolTS(int n, double ** A, double * b, double * x, double tol);
int gauss(double **A, double *v, double tol, int n);
int gausspivot(double ** A, double * v, double tol, int n);
double horner(float z, double * a, int n);
double spline(int n, double *x, double *M, double *h, double *N, double *L, double z);
double gausstri(double ** A, double * x, double tol, int n);