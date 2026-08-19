#include "Newton.h"
#include <stdio.h>

int main(void) {

    Newton teste = init();

    char polinomio[256];

    /*
        Exemplo de entrada:

        10+21+23+432

        representa:

        10 + 21x + 23x² + 432x³

        Os coeficientes estão em ordem crescente.
    */

    printf("Digite os coeficientes do polinomio:\n");
    printf("Exemplo: 10+21+23+432\n");
    printf("Polinomio: ");

    scanf("%255s", polinomio);

    /*
        Usa sua funcao get_poli exatamente como ela esta.
    */
    teste.get_poli(&teste, polinomio);


    /* Descobre o grau automaticamente */
    int grau = 0;

    for (int i = 0; i < tam_poli; i++) {
        if (teste.poli[i] != 0) {
            grau = i;
        }
    }

    printf("Grau detectado: %d\n", grau);


    /* Intervalo inicial */

    printf("\nDigite o valor de a: ");
    scanf("%lf", &teste.a);

    printf("Digite o valor de b: ");
    scanf("%lf", &teste.b);


    if (teste.a >= teste.b) {
        printf("Intervalo invalido: a deve ser menor que b.\n");
        return 1;
    }

    double fa = funcao(teste.poli, teste.a);
    double fb = funcao(teste.poli, teste.b);

    if (fa * fb > 0) {
        printf("Intervalo invalido: nao ha troca de sinal entre f(a) e f(b).\n");
        return 1;
    }

    /* Erro */

    printf("Digite o erro: ");
    scanf("%lf", &teste.erro);


    if (teste.erro <= 0) {
        printf("Erro invalido: o erro deve ser maior que zero.\n");
        return 1;
    }


    printf("\n========== METODO DE NEWTON ==========\n\n");

    teste.calcula_zero(&teste);

    printf("\n======================================\n");

    printf(
        "Raiz aproximada: %.10f\n",
        teste.x_n[teste.n]
    );

    printf(
        "Numero de iteracoes: %u\n",
        teste.n
    );


    return 0;
}