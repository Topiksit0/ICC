#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pracFuns.h"

int main(int argc, char const *argv[]){
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


}
