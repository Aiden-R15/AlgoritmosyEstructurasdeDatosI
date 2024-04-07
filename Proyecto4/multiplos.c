#include <stdio.h>
#include <stdbool.h>

void pedir_arreglo (int n_max, int a[]) {

    int i;
    i=0;

    while (i<n_max) {
        printf ("Ingrese un valor para la posicion %d del arreglo:\n", i);
        scanf ("%d", &a[i]);
        i = i+1;

    }
    
}

bool todos_pares(int tam, int a[]) {

    int i = 0;
    bool b;

    while (i<tam) {

        b = true;
        b = (a[i]%2==0) || b ;
        i = i+1;
    }

    return b;

}

bool existe_multiplo (int m, int tam, int a[]) {

    int i = 0;
    bool b;

    while (i<tam) {

        b = false;
        b = (m%a[i]==0) && b;
        i = i+1;
    }

    return b;

}

int main () {
    
    int tam, func;

    tam = printf ("Ingrese el tamaño que desea que tenga el arreglo:\n");
    scanf ("%d", &tam);
    int a [tam];
    pedir_arreglo (tam, a);
    func = printf ("Ingrese 1 para ejecutar la funcion todos_pares o 2 para ejecutar existe_multiplo:\n");
    scanf ("%d", &func);
    if (func==1){

        bool b;
        b = todos_pares (tam,a);
        printf ("%d\n", b);

    }
    else {

        int m;
        printf("Ingrese un valor para verificar si existen multiplos:\n");
        scanf ("%d", &m);
        bool b;
        b = existe_multiplo (m,tam,a);
        printf ("%d\n", b);
    }
    
    return 0;
}
