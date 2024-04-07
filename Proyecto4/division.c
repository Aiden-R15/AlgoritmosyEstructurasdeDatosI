#include <stdio.h>
#include <assert.h>

struct div_t {
int cociente;
int resto;
};

struct div_t division(int x, int y){
   
   assert (y != 0);

   struct div_t resultado;
    resultado.cociente = x/y;
    resultado.resto = x%y;

    return resultado;
   
}

int pedir_numero (char name) {

    int n;

    printf ("Ingrese un valor para el %c:\n", name);
    scanf("%d", &n);

    return n;

}

int main () {

    int x,y;
    struct div_t resultado;

    x = pedir_numero('n');
    assert (x>0);
    y = pedir_numero ('d');
    assert (y>0);
    resultado = division(x,y);
    printf ("El cociente de la division es: %d\nEl resto de la division es: %d\n", resultado.cociente, resultado.resto);

    return 0;

}
