#include <stdio.h>
#include <stdbool.h>

bool es_vocal (char letra) {
    
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
        return true;
    }
    else {
        return false;
    }

}

char pedir_letra () {

    char n;
    printf ("Ingrese un caracter: ");
    scanf(" %c", &n);

    return n;

}

int main () {

    char letra = pedir_letra();
    bool b = es_vocal (letra);

    if (b) {
        printf ("El caracter es una vocal\n");
    }
    else {
        printf ("El caracter no es una vocal\n");
    }

    return 0;

}