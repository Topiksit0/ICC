/* PALOMINO : VIVAR : MARCOS : 47132283Q / NIUB : 20329665 */
/* LOPEZ: RUIZ : GERARD : 46495842P / NIUB : 20274763*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pracFuns.h"

int main(int argc, char const *argv[]){
 int n, i, j, l;
    double result, interval1, interval2, tol, **A, *b, num, m, z, *h, *L, *N;

    char nom_fitxer_entrada[100], nom_fitxer_sort[100];
    FILE *fitxer_entrada;
    FILE *fitxer_sortida;

    printf("Donam els extrems del interval:\n");
    scanf("%le %le", &interval1, &interval2);

    printf("Dona'm el numero ded subintervals:\n");
    scanf("%d", &n);

    double valors_text[n];
    double valors_text_y[n];

    printf("Escriu la tolerància:\n");
    scanf("%le", &tol);


    printf("Dona'm el nom del fitxer que vols obrir:\n");
    scanf("%s", nom_fitxer_entrada);

    fitxer_entrada = fopen(nom_fitxer_entrada, "r");

    if (fitxer_entrada == NULL){
        printf("Error al obrir el fitxer\n");
        exit(1);
    }


    printf("Dona'm el nom del fitxer on escriurem els punts:\n");
    scanf("%s", nom_fitxer_sort);
    fitxer_sortida = fopen(nom_fitxer_sort, "w");


    if (fitxer_sortida == NULL){
        printf("Error al obrir el fitxer\n");
        exit(2);
    }

    for (i = 0; i < n; i++){
        fscanf(fitxer_entrada, "%le", &num);
        valors_text[i] = num;
    }

    for (i = 0; i < n; i++){
        fscanf(fitxer_entrada, "%le", &num);
        valors_text_y[i] = num;
    }



    A = (double **) malloc(n * sizeof(double *));

    if (A == NULL) {
        printf("No hi ha prou memòria\n");
        exit(3);
    }

    for (i = 0; i < n; i++) {
        A[i] = (double *) malloc(n * sizeof(double));

        if (A[i] == NULL) {
            printf("No hi ha prou memòria\n");
            exit(4);
        }
    }


    b = (double *) malloc(n * sizeof(double));
    h = (double *) malloc(n * sizeof(double));
    L = (double *) malloc(n * sizeof(double));
    N = (double *) malloc(n * sizeof(double));


    if (b == NULL) {
        printf("No hi ha prou memoria\n");
        exit(4);
    }
    for (i = 0; i < n; i++) {
        h[i] = valors_text[i + 1] - valors_text[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((j == 0 && i == 0)) {
                A[i][j] = 1;
                b[i] = 0;
            } else if ((j == n - 1) && (i == n - 1)) {
                A[i][j] = 1;
                b[i] = 0;
            } else {
                if ((i == 0) || (i == n - 1)) {
                    A[i][j] = 0;
                    b[i] = 0;
                } else {
                    if ((j == i - 1)) {
                        A[i][j] = (h[i]) / 6;
                    } else if ((j == i)) {
                        A[i][j] = ((h[i + 1]) + (h[i])) / 3;

                    } else if ((j == i + 1)) {
                        A[i][j] = (h[i + 1]) / 6;
                        b[i] = ((valors_text_y[i + 1] - valors_text_y[i]) / (valors_text[i + 2] - valors_text[i + 1])) -
                               ((valors_text_y[i] - valors_text_y[i - 1]) / (valors_text[i + 1] - valors_text[i]));
                    } else {
                        A[i][j] = 0;
                    }
                }
            }

        }
    }
    printf("\n sistema obtingut al final \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf(" %+10.6lf", A[i][j]);
        }
        printf(" | %+.6lf \n", b[i]);
    }

    result = gausstri(A, b, tol, n);

    for (i = 0; i < n - 1; i++) {
        L[i] = valors_text_y[i] - (b[i] * pow(h[i + 1], 2) / 6);
    }
    for (i = 0; i < n - 1; i++) {
        N[i] = ((valors_text_y[i + 1] - valors_text_y[i]) / h[i + 1]) - ((h[i + 1] / 6) * (b[i + 1] - b[i]));
    }

    if (result == 0){
        for (l = 0; l < 1001; l++){
            z = (interval1 + l*(interval2 - interval1)) / 1000;
            m = spline(n,valors_text,b,h,N,L,z);

            fprintf(fitxer_sortida, "%16.7e %16.7e", z, m);
        }

        printf("Dades guardades al fitxer correctament\n");
    }
    else{
        printf("Ha succeït un error\n");
    }



}
