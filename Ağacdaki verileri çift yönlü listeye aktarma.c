#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree {
	int veri;
	struct BinaryTree *sol, *sag;
}agac;

typedef struct DoubleList {
	int veri;
	struct DoubleList *onceki, *sonraki;
}liste;

liste *ilk = NULL, *son = NULL;

agac *dugumOlustur (int veri)
{
	agac *Eklenen = (agac*)malloc(sizeof(agac));
	Eklenen->veri = veri;
	Eklenen->sag = NULL;
	Eklenen->sol = NULL;
	return Eklenen;
}


agac *agacekle (agac *root, int veri)
{
	
	if (root == NULL)
		return dugumOlustur(veri);
	else
	{
		if(veri <= root->veri)
			root->sol = agacekle(root->sol,veri);
		else
			root->sag = agacekle(root->sag,veri);
	}
	return root;
}

liste *LdugumOlustur (int veri)
{
	liste *yeni = (liste*)malloc(sizeof(liste));
	yeni->veri = veri;
	yeni->onceki = NULL;
	yeni->sonraki = NULL;
	return yeni;
}

void listeEkle (int veri)
{
	liste *yeni = LdugumOlustur(veri);
	
	if (ilk == NULL)
	{
		ilk = yeni;
		son = yeni;
	}
	else
	{
		son->sonraki = yeni;
		yeni->onceki = son;
		son = yeni;
		son->sonraki = NULL;
	}
}

void aktarma (agac *root)
{
	if(root)
	{
		aktarma(root->sol);
		listeEkle(root->veri);
		aktarma(root->sag);
	}
}

void alistele (agac *root)
{
	if(root)
	{
		alistele(root->sol);
		printf("%d ",root->veri);
		alistele(root->sag);
	}
}

void llistele ()
{
	liste *gecici = ilk;
	
	while(gecici)
	{
		printf("%d ",gecici->veri);
		gecici = gecici->sonraki;
	}
}

int main()
{
	agac *root = NULL;
	root = agacekle(root, 50);
	root = agacekle(root, 40);
	root = agacekle(root, 30);
	root = agacekle(root, 20);
	root = agacekle(root, 60);
    root = agacekle(root, 70);
	root = agacekle(root, 80);
	
	
	alistele(root);
	
	aktarma(root);
	printf("\n");
	llistele();
}
