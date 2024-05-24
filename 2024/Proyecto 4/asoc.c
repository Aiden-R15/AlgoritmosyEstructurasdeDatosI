#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef char clave_t;
typedef int valor_t;

struct asoc {
    clave_t clave;
    valor_t valor;
};

bool asoc_existe (int tam, struct asoc a[], clave_t c) {

    int i = 0;
    while (i<tam) {
        if (a[i].clave==c) {
            return true;
        }
        else {}
        i = i+1;
    }

    return false;
    
}

void pedir_arreglo(int n_max, struct asoc a[]) {

    int i = 0;
    
    while (n_max>i) {

        printf ("Ingrese el valor %d del arreglo: ", i);
        scanf ("%d", &a[i].valor);
        printf ("Ingrese la clave para el valor %d del arreglo: ", i);
        scanf (" %c", &a[i].clave);
        i = i+1;

    }

}

clave_t pedir_clave()
{
    clave_t c;
    printf("Coloque el valor de la clave: ");
    scanf(" %c", &c);
    return c;
}

int main () {

    int tam;
    printf ("Ingrese el tamaño del arreglo: ");
    scanf ("%d", &tam);
    struct asoc a[tam];
    pedir_arreglo (tam, a);
    clave_t c = pedir_clave ();
    if (asoc_existe(tam, a, c)) {
        printf("La clave '%c' existe en el arreglo.\n", c);
    } else {
        printf("La clave '%c' no existe en el arreglo.\n", c);
    }

    return 0;

}

