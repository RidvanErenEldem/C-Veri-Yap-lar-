#include <stdio.h>
#include <stdlib.h>

typedef struct CiftYonluListe
{
    int veri;
    struct CiftYonluListe *onceki;
    struct CiftYonluListe *sonraki;
}kuyruk;

kuyruk *ilk = NULL, *son = NULL;

void ekle(int veri)
{
    kuyruk *yeni = (kuyruk*)malloc(sizeof(kuyruk));
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

void silme ()
{
    if (ilk == NULL)
        printf("\nKuyruk Boş\n");
    else if (ilk == son)
    {
        printf("\n%d silindi\n", ilk->veri);
        ilk = NULL;
        son = NULL;
    }
    else
    {
        printf("\n%d silindi\n", ilk->veri);
        ilk = ilk->sonraki;
        ilk->onceki = NULL; 
    }
}

void listele()
{
    if (ilk == NULL)
        printf("\nKuyruk Bos\n");
    else
    {
        kuyruk *gecici = ilk;

        while (gecici)
        {
            printf(" %d ", gecici->veri);
            gecici = gecici->sonraki;
        }
        printf("\n");
    }
}

int main() {
    ekle(5);
    ekle(10);
    listele();
    silme();
    listele();
    silme();
    listele();
    silme();
    ekle(10);
    listele();
    ekle(20);
    listele();
    return 0;
}
