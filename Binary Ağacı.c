#include <stdio.h>
#include <stdlib.h>

typedef struct ikiliAgac
{
    int veri;
    struct ikiliAgac *sag;
    struct ikiliAgac *sol;
}agac;

agac *yeniDugum (int veri)
{
    agac *yeni = (agac*)malloc(sizeof(agac));
    yeni->veri = veri;
    yeni->sag = NULL;
    yeni->sol = NULL;
    return yeni;
}

agac *ekleme (agac *kok , int veri)
{
    if (kok == NULL)
        return yeniDugum(veri);
    if (veri < kok->veri) 
        kok->sol = ekleme(kok->sol,veri);
    else
        kok->sag = ekleme(kok->sag,veri);

    return kok;
}

void inorder (agac *kok)
{
    if (kok != NULL)
    {
        inorder(kok->sol);
        printf("%d ", kok->veri);
        inorder(kok->sag);
    }
}

agac *enKucukDeger (agac *kok)
{
    agac *gecici = kok;

    while (gecici->sol !=NULL)
        gecici = gecici->sol;
        
    return gecici;
}

agac *silme (agac *kok, int veri)
{
    if (kok == NULL)
        return kok;
    if(veri < kok->veri)
        kok->sol = silme (kok->sol,veri);
    else if (veri > kok->veri)
        kok->sag = silme (kok->sag,veri);

    else
    {
        if (kok->sol == NULL)
        {
            agac *gecici = kok->sag;
            free(kok);
            return gecici;
        }
        else if (kok->sag == NULL)
        {
            agac *gecici = kok->sol;
            free(kok);
            return gecici;
        }

        agac *gecici = enKucukDeger (kok);

        kok->veri = gecici->veri;

        kok->sag = silme(kok->sag,veri);
    }
    return kok;
}
int main() {
    agac *kok = NULL;
    /* 
              50
           /     \
          30      70
         /  \       /  \
       20 40  60   80 */
    kok = ekleme (kok,50);
    kok = ekleme (kok,30);
    kok = ekleme (kok,20);
    kok = ekleme (kok,40);
    kok = ekleme (kok,70);
    kok = ekleme (kok,60);
    kok = ekleme (kok,80);

    printf("Inorder Siralama .. \n");
    inorder(kok);

    printf("\n20 sil\n");
    kok = silme(kok,20);

     printf("Inorder Siralama .. \n");
    inorder(kok);

    printf("\n30 sil\n");
    kok = silme(kok,30);

     printf("Inorder Siralama .. \n");
    inorder(kok);

    printf("\n50 sil\n");
    kok = silme(kok,50);

     printf("Inorder Siralama .. \n");
    inorder(kok);

    return 0;
}

