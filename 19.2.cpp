#include<stdio.h>
#include<conio.h>
#include<string.h>
struct student
{
	int gifts;
    char name[10];
    int price;
    int total;
}st[5];
int main()
{
	int i=0,n,b[10],w=10,m=0,ngifts=0;
	char g;
	printf("Enter the Number of people are going to attend an event\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("\nEnter the name of the each person:");
		scanf("%s",&st[i].name);
		printf("\nwe are buying no of gifts:\n");
        scanf("%d",&st[i].gifts);
	}
	for(i=0;i<m;i++)
	{
		printf("\n Enter the prize for each of the gift:");
		scanf("%d",&st[i].price);
	}
	for(i=0;i<m;i++)
	{
		st[i].total=st[i].total+st[i].price;
	}
	
	//printf("we are finding the person who have maximum no of gifts\n");
	for(i=0;i<m;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			if(st[j].gifts>=st[i].gifts)
			{
				int temp=st[i].gifts;
				st[i].gifts=st[j].gifts;
				st[j].gifts=temp;
			}
		}
	}
	//printf("enter the priority for each person to enter into  a billing counter\n");
	w=m;
	for(i=0;i<m;i++)
	{
		if(st[i].gifts>=st[i+1].gifts)
		{
			b[i]=w;
			w--;
		}
	}
	printf("we are displaying the persons in the order:\n");
	for(i=0;i<m;i++)
	{
		printf("%d\n",st[i].gifts);
	}
}
