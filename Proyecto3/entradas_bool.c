#include <stdio.h>
#include <stdbool.h>

char pedir_nombre () {

    char name;

    printf ("Ingrese un nombre para la variable:\n");
    scanf ("%c", &name);

    return name;

}

bool pedir_booleano (char name) {

    bool b;
    int y;

    printf("ingrese un valor booleano para %c (0 para falso, 1 para verdadero)\n", name);
    scanf("%d", &y);

    b = 0;
    if (y != 0){
        b = 1;
    }
    else{
        b = 0;
    }

    return b;
}

void imprimir_booleano (char name,bool b) {

    if (b == 1) {
        printf ("El valor del booleano %c que ingreso es: Verdadero\n", name);
    }
    else {
        printf ("El valor del booleano %c que ingreso es: Falso\n", name);
    }
}

int main () {
    
    bool b;
    char name;

    name = pedir_nombre();
    b = pedir_booleano(name);
    imprimir_booleano(name, b);

    return 0;

}