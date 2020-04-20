/*
	Name: Rýdvan Eren Eldem
	Date: 06.11.19 22:52
*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tyonlu{
	char ad[50];
	char soy[100];
	int yas;
	struct Tyonlu *adres;
}tl;

tl *ilk = NULL, *son = NULL;

void listeekle(char *adi, char *soyadi, int yasi)
{
	tl *Ydugum;
	Ydugum = (tl*)malloc(sizeof(tl));
	strcpy(Ydugum->ad,adi);
	strcpy(Ydugum->soy,soyadi);
	Ydugum->yas = yasi;
	Ydugum->adres = NULL;
	
	if(ilk == NULL)
	{
		ilk = Ydugum;
		son = Ydugum;
		son->adres = NULL;
	}
	else
	{
		son->adres = Ydugum;
		son = Ydugum;
		son->adres = NULL;
	}
}

void listele()
{
	int i=1;
	if(ilk == NULL)
		printf("Liste Boþ");
	else
	{
		tl *gecici;
		gecici = ilk;
		while (gecici!=NULL)
		{
			printf("%d. Düðümün verisi = %s %s %d\n",i,gecici->ad,gecici->soy,gecici->yas);
			gecici = gecici->adres;	
			i++;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	FILE *depo;
	
	depo = fopen("depo.txt","r");
	
	char adi[50];
	char soyadi[100];
	int yasi;
	
	while (!feof(depo))
	{
		fscanf(depo,"%s %s %d",adi,soyadi,&yasi);
		listeekle(adi,soyadi,yasi);
	}
	listele();
}
