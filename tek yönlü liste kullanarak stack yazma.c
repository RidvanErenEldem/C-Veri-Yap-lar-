#include <stdio.h>
#include <stdlib.h>


typedef struct TekYonluListe {
	int veri;
	struct TekYonluListe *adres;
}stack;

stack *ilk = NULL, *son = NULL;

void ekle(int veri)
{
	stack *yeni = (stack *)malloc(sizeof(stack));
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
	if (ilk == NULL)
		printf("\nstack is already empty");
	else if (ilk == son)
	{
		printf("\n%d is deleted",ilk->veri);
		ilk = NULL;
		son = NULL;
		
	}
	else
	{
		stack *gecici = ilk, *onceki;
		
		while (gecici)
		{
			if (gecici == son)
				break;
			onceki = gecici;
			gecici = gecici->adres;
		}
		
		onceki->adres = NULL;
		son = onceki;
		
		printf("\n%d is deleted", gecici->veri);
		
		free(gecici);
	}
}

void peek ()
{
	if (ilk == NULL)
		printf("\nyour stack is already empty bro");
	else
	{
		printf("\nYour Last item in the stack is %d",son->veri);
	}
}

int main()
{
	silme();
	ekle(3);
	ekle(5);
	peek();
	silme();
	ekle(10);
	peek();
	silme();
	peek();
	silme();
	peek();
	peek();
	silme();
}


