#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

//parcial 2 23-11-06 (tema H)

struct lienzo {
    int l1;
    int l2;
    int l3;
    int l4;
};

struct tipo_lienzo {
    bool es_figura;
    bool es_paisajes;
    bool ninguno_anteriores;
};

struct tipo_lienzo verificar_lienzo (struct lienzo t) {
    struct tipo_lienzo tl;
    tl.es_figura = false;
    tl.es_paisajes = false;
    tl.ninguno_anteriores = false;
    if (t.l1==t.l2&&t.l2==t.l3&&t.l3==t.l4) {
        tl.es_figura = true;
    }
    else {}
    if ((t.l1==t.l3&&t.l2==t.l4)&&t.l1!=t.l2) {
        tl.es_paisajes = true;
    }
    else {}
    if (!tl.es_figura&&!tl.es_paisajes) {
        tl.ninguno_anteriores = true;
    }
    else {}

    return tl;

}

int main () {
    struct lienzo t;
    printf ("Ingrese el primer lado del lienzo: ");
    scanf ("%d", &t.l1);
    printf ("Ingrese el segundo lado del lienzo: ");
    scanf ("%d", &t.l2);
    printf ("Ingrese el tercer lado del lienzo: ");
    scanf ("%d", &t.l3);
    printf ("Ingrese el cuarto lado del lienzo: ");
    scanf ("%d", &t.l4);
    struct tipo_lienzo tl = verificar_lienzo (t);
    printf ("Es_figura: %d\nEs_paisajes: %d\nNinguno_anteriores: %d\n",tl.es_figura,tl.es_paisajes,tl.ninguno_anteriores);

    return 0;

}