#include <stdio.h>
#include <locale.h>
#include <windows.h>

#define max 5

int q[max];
int front = 0;
int rear = 0;


void insertq ()
{
	int data;
	if (rear == max)
	{
		printf("\nKuyruk dolu !\n\n");
	}
	else
	{
		printf("\nBir Deðer Giriniz: ");
		scanf("%d", &data);
		q[rear]=data;
		rear++;
		printf("\nVeri kuyruða eklendi\n\n");
	}
}

void displayq()
{
	if(rear == 0)
	{
		printf("\nKuyruk boþ !\n\n");	
	}	
	else
	{
		printf("\n");
		int i;
		for(i=front;i<rear;i++)
		{
			printf("%i. kuyruk eleman deðeri = %i\n",(i+1),q[i]);
		}
		printf("\n");
	}
}

void deleteq ()
{
	if(front == rear)
	{
		printf("\nKuyruk boþ !\n\n");
	}
	
	else
	{
		printf("\nÇýkan eleman = %i\n\n",q[0]);
		int i;
		for	(i=front;i<(rear-1);i++)
		{
			q[i]=q[i+1];
		}
		rear--;
	}
}

int main()
{
	system("color 74");
	setlocale (LC_ALL ,"Turkish");
	int sec;
	printf("Hoþ Geldiniz\n");
	while (sec != 4)
	{
		printf("1-)Kuyruða Ekleme\n2-)Kuyruktan Çýkarma\n3-)Kuyruðu görüntüleme\n4-)Çýkýþ\nSeçim Yapýnýz : ");
		scanf("%d", &sec);
		switch (sec)
		{
			case 1 : {
				insertq();
				break;
			}
			case 2 : {
				deleteq();
				break;
			}
			case 3 : {
				displayq();
				break;
			}
			default : {
				break;
			}
		}
	}
	return 0;
}
