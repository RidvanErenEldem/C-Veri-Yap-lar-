#include <stdio.h>
#include <stdlib.h>

typedef struct Regular_queue {
	int data;
	struct Regular_queue *address;
}queue;

queue *first = NULL, *last;

void add_queue (int data)
{
	queue *recent;
	recent = (queue *)malloc(sizeof(queue));
	recent->data = data;
	recent->address = NULL;
	
	if (first== NULL)
	{
		first = (queue *)malloc(sizeof(queue));
		first = recent;
		last = recent;
	}
	else
	{
		last->address = recent;
		last = recent->address;
	}
	printf("Data added to the queue: %d\n", recent->data);
}

void del_queue()
{
	if (first == NULL)
	{
		printf("Queue is empty !\n");
	}
	else
	{
		queue *del;
		del = (queue *)malloc(sizeof(queue));
		del = first;
		first = first->address;
		printf("%d is deleted from to the queue", del->data);
		free(del);
	}
}

void list()
{
	if (first == NULL)
	{
		printf("Queue is empty");
	}
	else
	{
		queue *temp = first;
		while(temp)
		{
			printf("%d ",temp->data);
			temp = temp->address;
		}
	}
}

int main ()
{
	int option, data;
	
	printf("Welcome to this awsome program\nPlese Make A Choice\n1-)Add a number to queue\n2-)Delete a number to queue\n3-)List the queue\n4-)Exit\nChoose: ");
	
	while(option != 4)
	{
		
		scanf("%d",&option);
		
		switch (option)
		{
			case 1: {
				printf("Awesome now type a number for add to the queue: ");
				scanf("%d",&data);
				add_queue(data);
				break;
			}
			case 2: {
				del_queue();
				break;
			}
			case 3: {
				list();
				break;
			}
			case 4: {
				break;
			}
			default :{
				printf("Sorry bro wrong choice try again");
				break;
			}
		}
	}
}
