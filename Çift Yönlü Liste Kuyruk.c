#include <stdio.h>
#include <stdlib.h>

typedef struct kuyruk_liste {
	int veri;
	struct kuyruk_liste *onceki, *sonraki;
}dugum;

dugum *ilk = NULL, *son = NULL;

void ekle (int veri)
{
	dugum *Ydgm;
	Ydgm = (dugum *)malloc(sizeof(dugum));
	Ydgm->veri = veri;
	Ydgm->onceki = NULL;
	Ydgm->sonraki = NULL;
	
	if(ilk != NULL)
	{
		son->sonraki = Ydgm;
		Ydgm->onceki = son;
		son = son->sonraki;
	}
	else
	{
		Ydgm->onceki = NULL;
		ilk = Ydgm;
		son = Ydgm;
	}
}

void cikar()
{
	if (ilk != NULL)
	{
		dugum *sil;
		sil = ilk;
		ilk = ilk->sonraki;
		printf("\n%d kuyurkdan cikti\n\n",sil->veri);
		free(sil);
	}
	else
		printf("\nKuyruk Zaten Bos !\n\n");
}

void listele()
{
	if (ilk!=NULL)
	{
		dugum *gecici;
		gecici = ilk;
		printf("\n");
		while(gecici)
		{
			printf("%d   ",gecici->veri);
			gecici= gecici->sonraki;
		}
		printf("\n\n");
		free(gecici);
	}
	else
		printf("\nKuyruk Bos\n\n");
}

int main()
{
	int sec,veri;
	
	printf("-Cift Yonlu Liste ile Kuyruk Programi-\n");
	
	while (sec != 4)
	{
		printf("1-)Ekleme\n2-)Cikarma\n3-)Listeleme\n4-)Cikis\nSeciniz: ");
		scanf("%d",&sec);
		switch (sec)
		{
			case 1: {
				printf("Kuyruga eklenecek sayiyi giriniz: ");
				scanf("%d",&veri);
				ekle(veri);
				break;
			}
			case 2: {
				cikar();
				break;
			}
			case 3: {
				listele();
				break;
			}
			case 4: {
				break;
			}
			default : {
				printf("\nYanlis Secim Yaptiniz\n\n");
				break;
			}
		}
	}
}
