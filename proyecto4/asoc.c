#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef char clave_t;
typedef int valor_t;

struct asoc {
clave_t clave;
valor_t valor;
};

bool asoc_existe(int tam, struct asoc a[], clave_t c) {

    bool b = false;
    int i = 0;

    while (i!=tam && b==false) {
        if (c==a[i].valor) {
            b = true;
        }
        else {
        }
        i = i+1;
    }

    return b;

}

void pedir_arreglo (int n_max, struct asoc a[]) {

    int i;
    i=0;

    while (i!=n_max) {

        printf("Ingrese un valor para la posicion %d del arreglo\n",i);
        scanf("%d",&a[i].valor);
        
        printf("Ingrese una clave para asignarle al valor\n");
        scanf("%c",&a[i].clave);

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

int main()
{
    int tam;

    printf("Ingrese el tamaño del arreglo: \n");
    scanf("%d", &tam);
    
    struct asoc a[tam];

    pedir_arreglo(tam, a);
    clave_t clave = pedir_clave();
    if (asoc_existe(tam, a, clave))
    {
        printf("La clave %c existe en el arreglo\n",clave);
    }
    else{
        printf("La clave %c NO existe en el arreglo\n",clave);
    }

    return 0;
}