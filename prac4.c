#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pracFuns.h"

int main(int argc, char *argv[]){
    int n,k,i,j,l; 
    double interval1, interval2,tol, **A, *b, num,m,z; 

    char nom_fitxer_entrada[100], nom_fitxer_sort[100]; 
    FILE *fitxer_entrada;
    FILE *fitxer_sortida;

    printf("Donam els extrems del interval:\n");
    scanf("%le %le", &interval1, &interval2);

    printf("Dona'm el grau del polinomi:\n");
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



    A = (double **) malloc (n * sizeof(double *));

    if (A== NULL){
        printf("No hi ha prou memòria\n");
        exit(3);
    }

    for (i = 0; i < n; i ++){
        A[i] = (double *) malloc (n * sizeof(double));

        if (A[i] == NULL){
            printf("No hi ha prou memòria\n");
            exit(4);
        }
    }


    b = (double *) malloc (n * sizeof(double));


    if (b == NULL){
        printf("No hi ha prou memoria\n");
        exit(4);
    }


    // Omplim la matriu de Vandermonde

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (j == 0){
                A[i][j] = 1;
            }

            else{
                A[i][j] = pow(valors_text[k], j);
            }
        }


        b[i] = valors_text_y[i];
        k += 1;
    }

    for (i = 0; i <  n; i++){
        for (j = 0; j < n; j++){
            printf("%16.7e", A[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++){
        printf("%16.7e", b[i]);
    }
    printf("\n");


    double result = gauss(A, b, tol, n);


    if (result == 0){
        for (l = 0; l < 1001; l++){
            z = (interval1 + l*(interval2 - interval1)) / 1000;
            m = horner(z, b, n);

            fprintf(fitxer_sortida, "%16.7e %16.7e", z, m);
        }

        printf("Dades guardades al fitxer correctament\n");
    }
    else{
        printf("Ha succeït un error\n");
    }


    for (i = 0; i < n; i++){
        free(A[i]);
    }

    free(A);
    free(b);
    return 0;
    



}