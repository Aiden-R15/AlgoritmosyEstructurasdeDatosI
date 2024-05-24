#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void pedir_arreglo(int n_max, int a[]) {

    int i = 0;
    
    while (n_max>i) {
        printf ("Ingrese el valor %d del arreglo: ", i);
        scanf ("%d", &a[i]);
        i = i+1;
    }

}

bool todos_pares (int tam, int a[]) {

    int i = 0;
    while (tam>i) {
        if (a[i]%2==0) {
        }
        else {
            return false;
        }
        i = i+1;
    }

    return true;

}

bool existe_multiplo(int m, int tam, int a[]) {
    int i = 0;
    while (i<tam) {
        if (a[i]%m==0) {
            return true;
        }
        else{
        }
        i = i+1;
    }

    return false;
}

bool elegir_func () {

    int b;
    printf ("Ingrese 0 si desea ejecutar la funcion todos_pares, o 1 para ejecutar existe multiplo: ");
    scanf ("%d", &b);
    assert (b==1||b==0);

    return b;

}

int main () {

    int tam;
    printf ("Ingrese el tamaño del arreglo: ");
    scanf ("%d", &tam);
    int a[tam];
    pedir_arreglo (tam, a);
    bool b = elegir_func ();
    if (!b) {
        if (todos_pares (tam, a)) {
            printf ("Todos los elementos del arreglo son pares\n");
        }
        else {
            printf ("Hay elemento/s impar/es en el arreglo\n");
        }
    }
    else {
        int m;
        printf("Ingrese un valor para verificar si existe un multiplo en el arreglo: ");
        scanf ("%d", &m);
        if (existe_multiplo (m, tam, a)) {
            printf ("Existe multiplo de %d en el arreglo\n", m);
        }
        else {
            printf ("No existe multiplo de %d en el arreglo\n", m);
        }
    }

    return 0;

}