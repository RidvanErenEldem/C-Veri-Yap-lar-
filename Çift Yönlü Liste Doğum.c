#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct CiftYonluListe {
	int gun;
	int ay;
	int yil;
	char ad[100];
	char soyad[50];
	struct CiftYonluListe *onceki;
	struct CiftYonluListe *sonraki;
}Cliste;

Cliste *ilk = NULL, *son = NULL;

void ekle (int gun, int ay, int yil, char *ad, char *soyad)
{
	Cliste *Yeni;
	Yeni = (Cliste*)malloc(sizeof(Cliste));
	Yeni->gun = gun;
	Yeni->ay = ay;
	Yeni->yil = yil;
	strcpy(Yeni->ad,ad);
	strcpy(Yeni->soyad,soyad);
	Yeni->onceki = NULL;
	Yeni->sonraki = NULL;
	
	if(ilk != NULL)
	{
		son->sonraki = Yeni;
		Yeni->onceki = son;
		son = Yeni;
		son->sonraki = NULL;
	}
	else
	{
		ilk = Yeni;
		son = Yeni;
		ilk->sonraki = NULL;
		ilk->onceki = NULL;
	}
}

void listele()
{
	Cliste *gecici;
	gecici = ilk;
	if (ilk == NULL)
		printf("\nListe Bo�\n\n");
	while(gecici)
	{
		printf("\n%s %s %d.%d.%d\n\n",gecici->ad,gecici->soyad,gecici->gun,gecici->ay,gecici->yil);
		gecici = gecici->sonraki;
	}
}

Cliste *arama(int aranan)
{
	Cliste *gecici;
	gecici = ilk;
	while (gecici)
	{
		if (aranan == gecici->yil)
			return gecici;
		gecici = gecici->sonraki;
	}
	return NULL;
}

Cliste *silme(int silinecek)
{
	Cliste *gecici;
	gecici = arama(silinecek);
	if(gecici == NULL);
		return NULL;
	if (ilk == gecici)
	{
		if (ilk->sonraki != NULL)
		{
			ilk = gecici->sonraki;
			ilk->onceki = NULL;
		}
	}
	else
	{
		gecici->onceki->sonraki = gecici->sonraki;
		if (gecici == son)
			son = son->onceki;
		else
			gecici->sonraki->onceki = gecici->onceki;
	}
	free(gecici);
	return gecici;
}

void dosyayaEkle ()
{
	Cliste *gecici;
	gecici = ilk;
	
	FILE *dosya;
	
	dosya = fopen("veri.txt","w");
	
	while (gecici)
	{
		fprintf(dosya,"%s %s %d.%d.%d\n",gecici->ad,gecici->soyad,gecici->gun,gecici->ay,gecici->yil);
		gecici = gecici->sonraki;
	}
	printf("\nveri.txt dosyas�na eklendi !\n\n");
	fclose(dosya);
}

void dosyadanOku ()
{
	int gun, ay, yil;
	char ad[100], soyad[50];
	FILE *dosya;
	
	dosya = fopen("veri.txt","r");
	
	while (!feof(dosya))
	{
		fscanf(dosya,"%s %s %d.%d.%d",ad,soyad,&gun,&ay,&yil);
		printf("\n%s %s %d.%d.%d\n\n",ad,soyad,gun,ay,yil);
	}
	fclose(dosya);
}

int main ()
{
	setlocale (LC_ALL, "Turkish");
	int sec, gun, ay ,yil,aranan;
	char ad[100], soyad[50];
	Cliste *bulunan;
	
	printf("Ho�geldin ! \n\n");
	
	while (sec != 7)
	{
		printf("1-)�ift Y�nl� Listeye Ekelme\n2-)�ift Y�nl� Liste Listeleme\n3-)�ift Y�nl� Liste Arama\n4-)�ift Y�nl� Liste Silme\n5-)�ift Y�nl� Liste Dosyaya Ekleme\n6-)�ift Y�nl� Liste Dosyadan Okuma\n7-)��k��\nSe�iniz: ");
		scanf("%d",&sec);
		
		switch (sec)
		{
			case 1: {
				printf("Ad Giriniz: ");
				scanf("%s",ad);
				printf("Soyad Giriniz: ");
				scanf("%s",soyad);
				printf("Dogum Tarihini g�n.ay.y�l �eklinde giriniz: ");
				scanf("%d.%d.%d",&gun,&ay,&yil);
				ekle(gun,ay,yil,ad,soyad);
				break;
			}
			case 2: {
				listele();
				break;
			}
			case 3: {
				printf("Arada��n�z Ki�inin Do�um Y�l�n� Giriniz: ");
				scanf("%d",&aranan);
				bulunan = arama(aranan);
				if (bulunan == NULL)
					printf("\nArad���n�z Ki�i Bulunamad�\n\n");
				else
					printf("\nArad���n�z Ki�i = %s %s %d.%d.%d\n\n",bulunan->ad,bulunan->soyad,bulunan->gun,bulunan->ay,bulunan->yil);
				break;
			}
			case 4: {
				printf("Silmek �stedi�iniz Ki�inin Do�um Y�l�n� Giriniz: ");
				scanf("%d",&aranan);
				bulunan = silme(aranan);
				if (bulunan == NULL)
					printf("\nSilmek �stedi�iniz Ki�i Bulunamad�\n\n");
				else
					printf("\nSildi�iniz Ki�i = %s %s %d.%d.%d\n\n",bulunan->ad,bulunan->soyad,bulunan->gun,bulunan->ay,bulunan->yil);
				break;
			}
			case 5: {
				dosyayaEkle();
				break;
			}
			case 6: {
				dosyadanOku();
				break;
			}
			case 7: {
				break;
			}
			default : {
				printf("\nYanl�� Se�im Tekrar Deneyiniz\n\n");
				break;
			}
		}
	}
}
