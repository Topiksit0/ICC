/* PALOMINO : VIVAR : MARCOS : 47132283Q / NIUB : 20329665 */
/* LOPEZ: RUIZ : GERARD : 46495842P / NIUB : 20274763*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pracFuns.h"

int main(int argc, char *argv[]){
    int n,k = 0,i,j,l; 
    double interval1, interval2,tol, **A, *b, num,m,z; 

    char nomEntrada[100], nomSortida[100]; 
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
    scanf("%s", nomEntrada);

    fitxer_entrada = fopen(nomEntrada, "r");

    if (fitxer_entrada == NULL){
        printf("Error al obrir el fitxer\n");
        exit(1);
    }


    printf("Dona'm el nom del fitxer on escriurem els punts:\n");
    scanf("%s", nomSortida);
    fitxer_sortida = fopen(nomSortida, "w");

    

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



    for (i = 0; i < n; i ++){
        A[i] = (double *) malloc (n * sizeof(double));
    }

    b = (double *) malloc (n * sizeof(double));


    /* Rellenamos la matriz de Vandermonde*/
    for (i = 0; i < n; i++){
        for (j = 0; j < n ; j++){
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

    printf("\n la matriz Vandermonde es: \n");
    /* Imprimimos la matriz Vandermonde */
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
        printf("Error en la tolerancia indicada\n");
    }


    return 0;

}