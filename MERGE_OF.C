#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist
{
	int data;
	struct linkedlist *next, *prev;
}  *list;

list head1 = NULL, head2 = NULL, result = NULL;

list create()
{
	list temp = (list )malloc(sizeof(struct linkedlist));
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

list insertion (list first,int ele)
{
	list ptr = first, save = first, p = create();
	if(first==NULL||ele<=first->data)
	{
		p->data = ele;
		p->next = first;
		if(first!=NULL)
			first->prev = p;
		first = p;
		return first;
	}
	while(ptr!=NULL&&ptr->data<ele)
	{
		save = ptr;
		ptr = ptr->next;
	}
	p->data = ele;
	p->next = ptr;
	p->prev = save;
	save->next=p;
	if(ptr!=NULL)
		ptr->prev = p;
	return first;
}

list sorted(list first, list second)
{
	list p1=first, p2 = second,temp=NULL;
	while(p1!=NULL)
	{
		temp = insertion(temp,p1->data);
		p1 = p1->next;
	}
	while(p2!=NULL)
	{
		temp = insertion(temp, p2->data);
		p2 = p2->next;
	}
	return temp;
}

void display(list first)
{
	list temp=first;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void main()
{
	int ele;
	char ch1='y',ch2='y';
	clrscr();
	printf("Enter the elements for the first double linked list : \n");
	while(ch1=='y')
	{
		printf("Enter the element : ");
		scanf("%d",&ele);
		head1 = insertion (head1, ele);
		printf("Do you want another element (y/n)? : ");
		scanf(" %c",&ch1);
	}
	printf("Enter the elements for the second double linked list : \n");
	while(ch2=='y')
	{
		printf("Enter the element : ");
		scanf("%d",&ele);
		head2 = insertion (head2, ele);
		printf("Do you want another element (y/n)? : ");
		scanf(" %c",&ch2);
	}
	printf("The first double linked list is : ");
	display(head1);
	printf("The second double linked list is : ");
	display(head2);
	result = sorted(head1, head2);
	printf("The merging of the two sorted double linked lists is : \n");
	display(result);
	getch();
}

