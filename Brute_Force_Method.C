#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char T[100],P[100],count;

void bruteforce(char T[], char P[], int n, int m)
{
	int i,j;
	for(i=0;i<=n-m;i++)
	{
		j=0;
		while(j<m&&P[j]==T[i+j])
			j++;
		if(j==m)
			printf("The %d encounter of the substring in main string is at %d\n",++count,i);
	}
	if(count==0)
		printf("No such substring found in the main string\n");
}

void main()
{
	int i;
	clrscr();
	printf("Enter a string : ");
	gets(T);
	printf("Enter a substring : ");
	gets(P);
	bruteforce(T,P,strlen(T),strlen(P));
	getch();
}

