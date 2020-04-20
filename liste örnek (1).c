#include <stdio.h>
#include <stdlib.h>

typedef struct tekyonluliste {
	int veri1;
	float veri2;
	struct tekyonluliste *adres;
}Bliste;

Bliste *ilk = NULL, *son = NULL;

void listeekle ()
{
	int intveri;
	float floatveri;
	Bliste *Ydugum;
	Ydugum = (Bliste *)malloc(sizeof(Bliste));
	printf("Int veri giriniz: ");
	scanf("%i",&intveri);
	printf("Float veri giriniz: ");
	scanf("%f",&floatveri);
	Ydugum->veri1 = intveri;
	Ydugum->veri2 = floatveri;
	Ydugum->adres = NULL;
	
	if (ilk == NULL)
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
	if(ilk == NULL)
		printf("Liste Boþ");
	else
	{
		Bliste *gecici;
		gecici = ilk;
		while (gecici!=NULL)
		{
			printf("Dugum int veri = %i float veri = %.2f\n",gecici->veri1,gecici->veri2);
			gecici = gecici->adres;	
		}
	}
}

int main() 
{
	int j, veri1;
	float veri2;
	Bliste *gecici;
	
	FILE *F;
	
	F = fopen ("veri_1.txt","w");
	
	for(j=0;j<3;j++)
	{
		listeekle();
	}
	gecici = ilk;
	
	while (gecici)
	{
		fprintf(F,"%i,%.2f\n",gecici->veri1,gecici->veri2);
		gecici=gecici->adres;	
	}	
	printf("Yazma Ýþi tamam\n");
	fclose(F);
	listele();
}
