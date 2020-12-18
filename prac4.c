#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pracFuns.h"

int main(int argc, char *argv[]){
    int n; 
    double interval1; 
    double interval2; 
    double tol; 
    char nom_fitxer_entrada[80], nom_fitxer_sort[80]; 
    FILE *fitxer_entrada;
    FILE *fitxer_sortida;

    printf("Donam els extrems del interval:\n");
    scanf("%lf %lf", &interval1, &interval2);

    printf("Dona'm el grau del polinomi:\n");
    scanf("%d", &n);


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

    



}