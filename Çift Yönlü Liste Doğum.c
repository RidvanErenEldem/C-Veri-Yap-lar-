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
		printf("\nListe Boþ\n\n");
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
	printf("\nveri.txt dosyasýna eklendi !\n\n");
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
	
	printf("Hoþgeldin ! \n\n");
	
	while (sec != 7)
	{
		printf("1-)Çift Yönlü Listeye Ekelme\n2-)Çift Yönlü Liste Listeleme\n3-)Çift Yönlü Liste Arama\n4-)Çift Yönlü Liste Silme\n5-)Çift Yönlü Liste Dosyaya Ekleme\n6-)Çift Yönlü Liste Dosyadan Okuma\n7-)Çýkýþ\nSeçiniz: ");
		scanf("%d",&sec);
		
		switch (sec)
		{
			case 1: {
				printf("Ad Giriniz: ");
				scanf("%s",ad);
				printf("Soyad Giriniz: ");
				scanf("%s",soyad);
				printf("Dogum Tarihini gün.ay.yýl þeklinde giriniz: ");
				scanf("%d.%d.%d",&gun,&ay,&yil);
				ekle(gun,ay,yil,ad,soyad);
				break;
			}
			case 2: {
				listele();
				break;
			}
			case 3: {
				printf("Aradaðýnýz Kiþinin Doðum Yýlýný Giriniz: ");
				scanf("%d",&aranan);
				bulunan = arama(aranan);
				if (bulunan == NULL)
					printf("\nAradýðýnýz Kiþi Bulunamadý\n\n");
				else
					printf("\nAradýðýnýz Kiþi = %s %s %d.%d.%d\n\n",bulunan->ad,bulunan->soyad,bulunan->gun,bulunan->ay,bulunan->yil);
				break;
			}
			case 4: {
				printf("Silmek Ýstediðiniz Kiþinin Doðum Yýlýný Giriniz: ");
				scanf("%d",&aranan);
				bulunan = silme(aranan);
				if (bulunan == NULL)
					printf("\nSilmek Ýstediðiniz Kiþi Bulunamadý\n\n");
				else
					printf("\nSildiðiniz Kiþi = %s %s %d.%d.%d\n\n",bulunan->ad,bulunan->soyad,bulunan->gun,bulunan->ay,bulunan->yil);
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
				printf("\nYanlýþ Seçim Tekrar Deneyiniz\n\n");
				break;
			}
		}
	}
}
