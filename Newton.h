

#define tam_poli 11

typedef struct Newton Newton;

typedef struct Newton
{

    double poli[tam_poli];


    //int    *(*deriva)(Newton *self, int *polinomio);
    void   (*get_poli)(Newton *self, char *polinomio);
    char   (*escolhe_x)(Newton *self, int a, int b); 
    double (*erro)(Newton *self, int *poli);
    double (*calcula_zero)(Newton *self, int a, int b);

}Newton;


Newton init();

void   deriva (double *polinomio);
void   get_poli (Newton *self, char *polinomio);
char   escolhe_x (Newton *self, int a, int b); 
double erro (Newton *self, int *poli);
double calcula_zero (Newton *self, int a, int b);

