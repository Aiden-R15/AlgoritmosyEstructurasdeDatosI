#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

void llena_con_char (char a[], int tam) {

    int i = 0;
    while (i<tam) {

        printf ("Ingrese un valor para el valor %d del arreglo: ", i);
        scanf ("%c ", &a[i]);
        i = i+1;

    }

}

bool hay_mas_de_2_consonantes (char a[], int tam) {

    int i = 0;
    int cons = 0;

    while (i<tam) {
        
        if (a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u') {
        cons = cons+1;
        }
        else {
        }

        i=i+1;
    }
    
    if (cons>2) {
        return true;
    }
    else {
        return false;
    }
}

int main () {

    int tam;
    printf ("Ingrese un tamaño para el arreglo: ");
    scanf ("%d", &tam);
    char a[tam];
    llena_con_char (a,tam);
    if (hay_mas_de_2_consonantes(a,tam)) {
        printf ("En el array hay mas de 2 consonantes\n");
    }
    else {
        printf ("En el array no hay mas de 2 consonantes\n");
    }

    return 0;

}