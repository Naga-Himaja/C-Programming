#include<stdio.h>
#include<math.h>
int n,a[50];
void insert()
{
	int i,pos,ele;
	printf("Enter the element to be inserted : ");
	scanf("%d",&ele);
	printf("Enter the position : ");
	scanf("%d",&pos);
	if(pos>n||pos<0)
	{
		printf("Invalid position!");
		return;
	}
	for(i=n-1;i>=pos;i--)
	{
		a[i+1] = a[i];
	}
	a[pos] = ele;
	n++;
}

void deletion()
{
	int i,pos;

	printf("Enter the index for deletion : ");
	scanf("%d",&pos);
	if(pos>=n||pos<0)
	{
		printf("Invalid position.\n");
		return;
	}
	printf("The deleted element is : %d\n",a[pos]);
	for(i=pos;i<n-1;i++)
		a[i]=a[i+1];
	n--;
}

void search()
{
	int ele,i;
	printf("Enter the search element : ");
	scanf("%d",&ele);
	for(i=0;i<n;i++)
	{
		if(a[i] == ele)
		{
			printf("Element found at index %d\n",i);
			return;
		}
	}
	printf("Element not found\n");
}

 void secondhigh()
 {
	int max=a[0],max2=max, i;
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max2 = max;
			max = a[i];
		}
		else if(a[i]<max && a[i]>max2)
			max2 = a[i];
	}
	if(max!=max2)
		printf("The 2nd highest element is : %d\n",max2);
	else
		printf("All the elements are same!\n");
 }
 void display()
 {
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
 }
 void sumOfSquares(int a[])
 {
	int i,sum=0;
	if(n==0)
	{
		printf("Array is empty\n");
		return;
	}
	for(i = 0;i<n;i++)
	{
		if(a[i]>0&&ceil(sqrt(a[i]))==sqrt(a[i]))
		sum+=a[i];
	}
	printf("The sum of the sqaures is %d\n",sum);
 }

 void main()
 {
	int i,ch;
	clrscr();
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("1.Insertion\n2.Deletion\n3.Search\n4.Second Highest\n5.Display\n6.Sum Of Squares\n7.Exit\n");
	printf("Choose your option : ");
	scanf("%d",&ch);
	while(ch<7)
	{
		switch(ch)
		{
			case 1:; if(n<50)
					insert();
				 else
					printf("Overflow\n");
				 break;
			case 2:; if(n==0)
					printf("Underflow\n");
				 else
					deletion();
				 break;
			case 3:; if(n==0)
					printf("Array is empty.\n");
				 else
					search();
				 break;
			case 4:; if(n==0||n==1)
					printf("Array insufficient");
				 else
					secondhigh();
				 break;
			case 5:; if(n==0)
				printf("Empty array\n");
				else
				 display();    break;
			case 6: sumOfSquares(a); break;
		}
		printf("1.Insert\n2.Deletion\n3.Search\n4.Second highest\n5.Display\n6.Sum Of Squares\n7.Exit\n");
		printf("Choose your option : ");
		scanf("%d",&ch);
	}
 }

