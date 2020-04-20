#include <stdio.h>
#include <stdlib.h>

typedef struct tekyonliste {
	int veri;
	struct tekyonliste *adres;
}bliste;

bliste *ilk = NULL, *son = NULL;

void listeyeekle(bliste *eklenen)
{
	if(ilk==NULL)
	{
		ilk = eklenen;
		son = eklenen;
		son->adres = NULL;
	}
	else
	{
		son->adres = eklenen;
		son = eklenen;
		son->adres = NULL;
	}
}

bliste *dugum ()
{
	bliste *YeniDugum;
	YeniDugum = (bliste*)malloc(sizeof(bliste));
	printf("Veri Giriniz: ");
	scanf("%i",&YeniDugum->veri);
	YeniDugum->adres = NULL;
	return YeniDugum;
}

void listele()
{
	if(ilk == NULL)
		printf("Liste Boþ");
	else
	{
		bliste *gecici;
		gecici = ilk;
		while (gecici!=NULL)
		{
			printf("Dugum veri = %i\n",gecici->veri);
			gecici = gecici->adres;	
		}
	}
}

bliste *listeara(int aranan)
{
	bliste *gecici;
	gecici = ilk;
	while(gecici!=NULL)
	{
		if(aranan == gecici->veri)
		{
			printf("Aranan Deger = %i\n",gecici->veri);
			return gecici;
		}
		gecici=gecici->adres;
	}
	printf("Aranan Deger Yok !");
	return NULL;
}

void listesil(int aranan)
{
	bliste *gecici, *onceki;
	gecici = ilk;
	
	while(gecici)
	{
		if (aranan == gecici->veri)
			break;
		onceki = gecici;
		gecici = gecici->adres;
	}
	
	if(gecici!=NULL)
	{
		if(gecici==ilk)
		{
			if(gecici==son)
			{
				ilk = NULL;
				son = NULL;
			}
			else
			{
				ilk= ilk->adres;
			}
		}
		else
		{
			onceki->adres = gecici->adres;
			if(gecici==son)
			{
				son = onceki;
			}
		}
		printf("Dugum Silindi !");
		free(gecici);
	}
	else
		printf("Aranan Deger Bulunamadý !");
}

void main()
{
	
}
