#include <stdio.h>
#include <stdlib.h>

typedef struct TekYonluListe {
    int veri;
    struct TekYonluListe *adres;
}kuyruk;

kuyruk *ilk = NULL, *son = NULL;

void ekle (int veri)
{
    kuyruk *yeni = (kuyruk *)malloc(sizeof(kuyruk));
    yeni->veri = veri;
    yeni->adres = NULL;

    if (ilk == NULL)
    {
        ilk = yeni;
        son = yeni;
        son->adres = NULL;
    }
    else
    {
        son->adres = yeni;
        son = yeni;
        son->adres = NULL;
    }
}

void silme ()
{
    if(ilk == NULL)
        printf ("\nYour kuyruk is empty\n");
    else
    {
        printf("\n%d is deleted\n",ilk->veri);
        ilk = ilk->adres;
    }
}

void listele()
{
    if (ilk == NULL)
        printf("\nYour kuyruk is empty\n");
    else
    {
        kuyruk *gecici = ilk;

        while (gecici)
        {
            printf(" %d ", gecici->veri);
            gecici = gecici->adres;
        }
        printf("\n");
    }
}

int main()
{
    ekle(3);
    ekle(5);
    listele();
    silme();
    listele();
    ekle(10);
    listele();
    silme();
    silme();
    listele();
}
