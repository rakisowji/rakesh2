#include<stdio.h>
#include<conio.h>
struct student
{
	int stu[10];
}st;
int main()
{
	int i,n,b[10],w=10,m;
	printf("Enter the Number of people are going to attend an event\n");
	scanf("%d",&m);
//	printf("All are going to buy gifts:\n");
//	for(i=0;i<m;i++)
//	{
//		scanf("%d",&st.stu[i]);
//	}
	printf("we are buying no of gifts:\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&n);
		st.stu[i]=n;
	}
	printf("we are finding the person who have maximum no of gifts\n");
	for(i=0;i<m;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			if(st.stu[j]>=st.stu[i])
			{
				int temp=st.stu[i];
				st.stu[i]=st.stu[j];
				st.stu[j]=temp;
			}
		}
	}
	//printf("enter the priority for each person to enter into  a billing counter\n");
	for(i=0;i<10;i++)
	{
		if(st.stu[i]>=st.stu[i+1])
		{
			b[i]=w;
			w--;
		}
	}
	printf("we are displaying the persons in the order:\n");
	for(i=0;i<m;i++)
	{
		printf("%d\n",st.stu[i]);
	}
}
