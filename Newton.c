#include "Newton.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




Newton init(){
    Newton p;

    //p.deriva       = deriva;
    p.get_poli     = get_poli;
    p.escolhe_x    = escolhe_x;
    p.erro         = erro;
    p.calcula_zero = calcula_zero;

    return p;
}

double funcao(double *polinomio){

    for(int i = 0;i < tam_poli;i++){
        
    }

}

void deriva (double *polinomio){

    int i = 1;
    while(i < tam_poli /*&& polinomio[i] != 0*/){
        polinomio[i] *= i;
        i++;
    }
    memmove(polinomio, polinomio + 1,(tam_poli - 1)*sizeof(double));
    polinomio[i-1] = 0;
}

void get_poli (Newton *self, char *polinomio){

    char *ptr = polinomio;
    char *fim;
    unsigned ind = 0;

    while (*ptr != '\0') {
        double long numero = strtod(ptr, &fim);

        if (ptr == fim) {
            break;
        }

        self->poli[ind++] = (int)numero;

        ptr = fim;
    }
}

char escolhe_x (Newton *self, int a, int b){

    double *segunda_der;
    memcpy(segunda_der,self->poli,tam_poli);

    deriva(segunda_der);
    deriva(segunda_der);



}
double erro (Newton *self, int *poli){


}
double calcula_zero (Newton *self, int a, int b){


}



int main(){

    Newton teste;

    init(&teste);
    get_poli(&teste,"+10+10+0+28+12");
    for(unsigned i = 0;i < tam_poli;i++){
        printf("%f,",teste.poli[i]);

    }
    printf("\n");
    deriva(teste.poli);
    for(unsigned i = 0;i < tam_poli;i++){
        printf("%f,",teste.poli[i]);

    }

    return 0;
}
