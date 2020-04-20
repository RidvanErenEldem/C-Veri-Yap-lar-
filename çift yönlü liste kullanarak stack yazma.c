#include <stdio.h>
#include <stdlib.h>

typedef struct CiftYonluListe
{
    int veri;
    struct CiftYonluListe *onceki;
    struct CiftYonluListe *sonraki;
}stack;

stack *ilk = NULL, *son = NULL;

void ekle (int veri)
{
    stack *yeni = (stack*)malloc(sizeof(stack));
    yeni->veri = veri;
    yeni->onceki = NULL;
    yeni->sonraki = NULL;

    if (ilk == NULL)
    {
        ilk = yeni;
        son = yeni;
    }
    else
    {
        son->sonraki = yeni;
        yeni->onceki = son;
        son = yeni;
        son->sonraki = NULL;
    }
}

void silme()
{
    if (ilk == NULL)
        printf("\n Your stack is empty\n");
    else if (ilk == son)
    {
        printf("\n%d has been deleted\n", ilk->veri);
        ilk = NULL;
        son = NULL;
    }
    else
    {
        printf("\n%d has been deleted\n", son->veri);
        son = son->onceki;
        son->sonraki = NULL;
    }
}

void peek()
{
    if (ilk == NULL)
        printf("\nYour stack is empty\n");
    else
        printf("\nYour last item on stack is %d\n",son->veri);
}

int main() {

    peek();
    ekle(3);
    peek();
    ekle(5);
    peek();
    silme();
    peek();
    silme();
    peek();
    peek();
    silme();
    ekle(10);
    peek();

    return 0;
}
