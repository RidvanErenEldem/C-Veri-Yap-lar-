#include <stdio.h>
#include <stdlib.h>
typedef struct Sayilar
{
    int Sayi;
    struct Sayilar *sayiadresi;
}ciftsayilar;

ciftsayilar *ilk=NULL,*son=NULL;

void ListeyeEkle(int ciftsayi)
{
    ciftsayilar *lc;
    lc=(ciftsayilar*)malloc(sizeof(ciftsayilar));
    lc->Sayi=ciftsayi;
    lc->sayiadresi = NULL;
    
    if (ilk==NULL)
    {
        ilk = lc;
        son = lc;
        son->sayiadresi = NULL;
    }
    else
    {
        son->sayiadresi=lc;
        son = lc;
        son->sayiadresi=NULL;
    }    
}

void listele()
{
	if(ilk == NULL)
		printf("Liste Boþ");
	else
	{
		ciftsayilar *gecici;
		gecici = ilk;
		while (gecici!=NULL)
		{
			printf("Dugum veri = %i\n",gecici->Sayi);
			gecici = gecici->sayiadresi;	
		}
	}
}

void dosyayaz()
{
	FILE *f;
	
	f = fopen("cift.txt","w");
	ciftsayilar *gecici;
	gecici = ilk;
	if(ilk == NULL)
		printf("Liste Bos");
	else
	{
		while (gecici!= NULL)
		{
			fprintf(f,"%d ",gecici->Sayi);
			gecici = gecici->sayiadresi;
		}
	}
	fclose(f);
}
int main()
{
	
    int deger,i=1;
    while (i<=10)
    {
        printf("Sayi Giriniz: ");
        scanf("%d",&deger);
        if ((deger%2)==0)
        {
            ListeyeEkle(deger);
        }
        i++;
    }
    
    listele();
    
    dosyayaz();
    
    return 0;
}
