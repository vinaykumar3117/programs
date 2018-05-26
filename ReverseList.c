#include<stdio.h>

typedef struct List
{
	int num;
	struct List *link;
}LIST;

LIST *AddNext(LIST *head, int elem)
{
	LIST *new, *temp;
	new = malloc(sizeof(LIST));
	new->num = elem;
	new->link = NULL;
	if(head == NULL)
	{
		head = new;
	}
	else
	{
		temp = head;
		while(temp->link != NULL)
			temp = temp->link;
		temp->link = new;
	}
	return head;
}

LIST *AddPrev(LIST *head, int elem)
{
	LIST *new, *temp;
	new = malloc(sizeof(LIST));
	new->num = elem;
	if(head == NULL)
	{
		new->link = NULL;
	}
	else
	{
		new->link = head;
	}
	return new;
}

void PrintList(LIST *head)
{
	LIST *temp;
	if(head == NULL)
		printf("List is Empty\n");
	else
	{
		temp = head;
		while(temp != NULL)
		{
			printf("%d ", temp->num);
			temp = temp->link;
		}
		printf("\n");
	}
}

void FreeList(LIST *head)
{
	LIST *temp;
	if(head == NULL)
                printf("List is Empty\n");
        else
        {
		temp = head;
                while(temp != NULL)
                {
			head = temp;
                        temp = temp->link;
			free(head);
                }
        }
}

int main()
{
	int i;
	LIST *head1, *head2, *temp;
	head1 = AddNext(head1, 10);
	head1 = AddNext(head1, 20);
	head1 = AddNext(head1, 30);
	printf("Actual List : ");
	PrintList(head1);
	temp = head1;
	while(temp != NULL)
	{
		head2 = AddPrev(head2, temp->num);
		temp = temp->link;
	}
	printf("Reverse List : ");
	PrintList(head2);
	FreeList(head1);
	FreeList(head2);
	return 0;
}
