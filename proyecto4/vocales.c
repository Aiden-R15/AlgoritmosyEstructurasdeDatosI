#include <stdio.h>
#include <stdbool.h>

bool es_vocal (char letra) {

    bool b;
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
        b = true;
    }
    else {
        b = false;
    }

    return b;

}
int main () {

    char letra;
    bool b;

    printf ("Ingrese un caracter:\n");
    scanf ("%c", &letra);
    b = es_vocal (letra);
    if (b == true) {
        printf ("El caracter que ingreso es una vocal\n");
    }
    else {
        printf ("El caracter que ingreso no es una vocal\n");
    }

    return 0;

}