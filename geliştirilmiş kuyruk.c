#include <stdio.h>
#include <locale.h>

#define max 5

int queue[max];

void insert(int rear, int data)
{
	if (rear == max)
		printf("\nKuyruk Dolu !\n\n");
	else
	{
		queue[rear] = data;
		printf("\n%d Verisi kuyruða eklendi\n\n", data);
	}
}

void display(int front,int rear)
{
	if (rear == 0)
		printf("\nKuruk Boþ !\n\n");
	else
	{
		int i;
		printf("\n");
		for(i=front;i<rear;i++)
		{
			printf("Kuyruðun %d. verisi = %d\n", (i+1),queue[i]);
		}
		printf("\n");
	}
}

void del(int front, int rear)
{
	if (front == rear)
	{
		printf("\nKuyruk Boþ !\n\n");
	}
	else
	{
		int i;
		printf("\nÇýkmýþ olan veri = %d\n\n",queue[0]);
		for(i = front;i<(rear-1);i++)
			queue[i]=queue[i+1];
	}
}	

int main()
{
	setlocale (LC_ALL , "Turkish");
	
	int front = 0, rear = 0, data, sec;
	printf("Hoþ Geldiniz !\n");
	while (sec != 4)
	{
		printf("1-)Kuyruða Ekleme Yapma\n2-)Kuyruktan Çýkarma Yapma\n3-)Kuyruðu Görüntüleme\n4-)Çýkýþ\nSeçim Yapýnýz : ");
		scanf("%d", &sec);
		switch (sec)
		{
			case 1 : {
				printf("Eklenecek sayýsal veriyi giriniz: ");
				scanf("%d", &data);
				insert(rear,data);
				if (rear != max)
				{
					rear++;
				}
				break;
			}
			case 2: {
				del(front,rear);
				if (rear != front)
				{
					rear--;
				}
				break;
			}
			case 3: {
				display(front,rear);
				break;
			}
			case 4: {
				break;
			}
			default : {
				printf("\nHatalý Giriþ\n\n");
				break;
			}
		}
	}
}
