#include <stdio.h>
#include <stdbool.h>

struct comp_t {
int menores;
int iguales;
int mayores;
};

struct comp_t cuantos(int tam, int a[], int elem) {
    
    int i = 0;
    struct comp_t total;
    total.menores = 0;
    total.iguales = 0;
    total.mayores = 0;

    while (i!=tam) {

        if (a[i]<elem) {
            total.menores = total.menores + 1;
        }
        else {
            if (a[i]>elem) {
                total.mayores = total.mayores + 1;
            }
            else {
                total.iguales = total.iguales + 1;
            }
        }

        i = i + 1;
    }

    return total;
    
}

void pedir_arreglo (int n_max, int a[]) {

    int i;
    i=0;

    while (i!=n_max) {
        printf ("Ingrese un valor para la posicion %d del arreglo:\n", i);
        scanf ("%d", &a[i]);
        i = i+1;

    }
    
}
int main () {

    int tam, elem;
    struct comp_t total;

    tam = printf ("Ingrese el tamaño que desea que tenga el arreglo:\n");
    scanf ("%d", &tam);
    int a[tam];
    pedir_arreglo (tam, a);
    printf ("Ahora ingrese un elemento para buscar los valores mayores, menores o iguales:\n");
    scanf ("%d", &elem);
    total = cuantos (tam, a, elem);
    printf ("La cantidad de valores mayores a %d es: %d\nLa cantidad de valores menores es: %d\nLa cantidad de valores iguales es: %d\n", elem, total.mayores, total.menores, total.iguales);

    return 0;

}