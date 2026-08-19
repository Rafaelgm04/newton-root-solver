#define tam_poli 11
#define limete   100
#define eps      1e-9

typedef struct Newton Newton;

typedef struct Newton
{

    double poli[tam_poli];
    double erro;
    double a,b;

    double x_n[limete + 1];
    unsigned n;
    //int    *(*deriva)(Newton *self, int *polinomio);
    void     (*get_poli)(Newton *self, char *polinomio);
    double   (*escolhe_x)(Newton *self); 
    void     (*calcula_zero)(Newton *self);

}Newton;


Newton init();

void   deriva (double *polinomio);
void   get_poli (Newton *self, char *polinomio);
double   escolhe_x (Newton *self); 
void calcula_zero (Newton *self);
double funcao(double *, double);

