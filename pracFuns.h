#ifndef PRACFUNS_H_
#define PRACFUNS_H_
/* PALOMINO : VIVAR : MARCOS : 47132283Q / NIUB : membre1 de la parella */
/* LOPEZ : RUIZ : GERARD : 46495842P / NIUB : 20274763 */


int resolTS (int n, double **A, double *b, double *x, double tol);
void prodMatVec (double **A, double *x, double *y, int n);
double norma2 (int n, double *z);
int gauss(double **A, double *v, double tol, int n);
int gausspivot(double **A, double *v, double tol, int n);
#endif