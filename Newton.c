#include "Newton.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




Newton init(){
    Newton p = {0};

    //p.deriva       = deriva;
    p.get_poli     = get_poli;
    p.escolhe_x    = escolhe_x;
    p.calcula_zero = calcula_zero;

    return p;
}

double funcao(double *polinomio,double x){

    double resu = 0;
    for(int i = 0;i < tam_poli;i++){

        resu += polinomio[i] * pow(x,i);  
    }
    return resu;
}

void deriva (double *polinomio){

    int i = 1;
    while(i < tam_poli /*&& polinomio[i] != 0*/){
        polinomio[i] *= i;
        i++;
    }
    memmove(polinomio, polinomio + 1, (tam_poli - 1) * sizeof(double));
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

        self->poli[ind++] = numero;

        ptr = fim;
    }
}

double escolhe_x (Newton *self){

    double segunda_der[tam_poli];
    memcpy(segunda_der,self->poli,tam_poli * sizeof(double));

    deriva(segunda_der);
    deriva(segunda_der);

    if(funcao(self->poli,self->a)*funcao(segunda_der,self->a) > 0)
        return self->a;
    else
        return self->b;

}


void calcula_zero (Newton *self){
    //memset(self->x_n, 0, sizeof(self->x_n));
    self->x_n[0] = self->escolhe_x(self);

    double derivada[tam_poli];
    memcpy(derivada,self->poli,tam_poli * sizeof(double));
    deriva(derivada);


    unsigned n = 0;
    while (n < limete) {

        double fx = funcao(
            self->poli,
            self->x_n[n]
        );

        double dfx = funcao(
            derivada,
            self->x_n[n]
        );

        // evita divisao por zero
        if (fabs(dfx) < 1e-12) {
            printf("Derivada igual ou muito proxima de zero!\n");
            self->n = n;
            return;
        }

        self->x_n[n + 1] =
            self->x_n[n] - fx / dfx;

        printf("x[%u] = %.10f",n + 1,self->x_n[n + 1]);

        
        printf("   erro |(%f) - (%f)| = %f\n",
            self->x_n[n + 1],
            self->x_n[n],
            fabs(self->x_n[n + 1] - self->x_n[n])
        );

        if (
            fabs(self->x_n[n + 1] - self->x_n[n])
            < self->erro
        ) {
            self->n = n + 1;
            return;
        }

        n++;
    }

    printf("O programa atingiu o limite!\n");

    self->n = n;
}



int main(){


    Newton teste;

    teste = init();
    get_poli(&teste,"+10+10+0+28+12");
    teste.a = -3;
    teste.b = -2;
    teste.erro = 0.000001;
    calcula_zero(&teste);
    printf("%u zero: %f",teste.n, teste.x_n[teste.n]);
    /*
    for(unsigned i = 0;i < tam_poli;i++){
        printf("%f,",teste.poli[i]);

    }
    printf("\n");
    deriva(teste.poli);
    for(unsigned i = 0;i < tam_poli;i++){
        printf("%f,",teste.poli[i]);

    }

    double resu = funcao(teste.poli,1);
    printf("\nresu: %f\n",resu);
    */
    return 0;
}
