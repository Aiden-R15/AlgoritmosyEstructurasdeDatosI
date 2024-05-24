#include <stdio.h>
#include <stdbool.h>

struct comp_t {
int menores;
int iguales;
int mayores;
};

struct comp_t cuantos(int tam, int a[], int elem) {
    
    struct comp_t res;
    res.iguales = 0;
    res.mayores = 0;
    res.menores = 0;
    int i = 0;

    while (i<tam) {
        if (a[i]==elem) {
            res.iguales = res.iguales+1;
        }
        else {
            if (a[i]>elem) {
                res.mayores = res.mayores+1;
            }
            else {
                res.menores = res.menores+1;
            }
        }
        i = i+1;
    }

    return res;

}

void pedir_arreglo(int n_max, int a[]) {

    int i = 0;
    
    while (n_max>i) {
        printf ("Ingrese el valor %d del arreglo: ", i);
        scanf ("%d", &a[i]);
        i = i+1;
    }

}

int pedir_entero () {

    int n;
    printf ("Ingrese un numero entero: ");
    scanf("%d", &n);

    return n;

}

int main () {

    int tam, elem;
    struct comp_t total;

    printf ("Ingrese el tamaño del arreglo: ");
    scanf ("%d", &tam);
    int a[tam];
    pedir_arreglo (tam,a);
    elem = pedir_entero ();
    total = cuantos (tam, a, elem);
    printf ("La cantidad de valores mayores a %d es: %d\nLa cantidad de valores menores es: %d\nLa cantidad de valores iguales es: %d\n", elem, total.mayores, total.menores, total.iguales);

    return 0;

}