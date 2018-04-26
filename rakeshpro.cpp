#include<stdio.h>
#include<conio.h>
struct round_robin
{
	int bursttime, waittime, id , prior, arrtime ,runtime ,tatime , exectime ,comptime;
}stu[10];
struct round_robin readyqueue[10];
struct round_robin p_id;//p_id is a idle process.
int time=0,rem_time,g1=0,m;
struct round_robin var;
struct round_robin var2;
struct round_robin protemp;
struct round_robin protemp1;
void getdata(struct round_robin stu[],int t)
{
	int i;
	for(i=0;i<t;i++)
	{		
		stu[i].id=i+1;
		printf("\nEnter arrival time of p%d:",i+1);
		scanf("%d",&stu[i].arrtime);
		printf("\nEnter burst time of p%d:",i+1);
		scanf("%d",&stu[i].bursttime);
		stu[i].runtime=stu[i].bursttime;
		printf("Enter the priority of the process p%d:",i+1);
		scanf("%d",&stu[i].prior);
		stu[i].exectime=0;
	}
}
void getwttat(struct round_robin stu[],int t1)
{
    int z;
    for(z=0;z<t1;z++)
    {   
    	stu[z].waittime=stu[z].comptime-stu[z].bursttime-stu[z].arrtime;
    	stu[z].tatime=stu[z].waittime+stu[z].bursttime;
    	printf("\nP%d:",stu[z].id);
    	printf("\nWaiting time:%d\n",stu[z].waittime);
    	printf("\nTurnAroundTime:%d\n",stu[z].tatime);
    }
}
main()
{
	p_id.arrtime=0;
	p_id.bursttime=10000;
	p_id.id=0;
	p_id.prior=0;
	p_id.runtime=p_id.bursttime;
	readyqueue[0]=p_id;
	int u,i,j,k,l,o,m,size=0,quant=0,istart=0;
	printf("\nEnter the Number of process:");
	scanf("%d",&m);
	printf("\n Enter the time quantum:");
	scanf("%d",&quant);
	rem_time=m;
	getdata(stu,m);
	 printf("\nGanttChart for every second is:");
	 while(rem_time!=0)
	 {
	 	for(i=0;i<m;i++)
	 	{
	 	 if(stu[i].arrtime==time&&stu[i].exectime==0)
	 	 {
	 		readyqueue[size]=stu[i];
	 		stu[i].exectime=1;
	 		size++;
	 		for(j=0;j<size-1;j++)
		   {
		    for(k=0;k<size-j-1;k++)
		 	{
		 		if(readyqueue[k].prior<readyqueue[k+1].prior)
		 		{
		 			var=readyqueue[k];
		 			readyqueue[k]=readyqueue[k+1];
		 			readyqueue[k+1]=var;
				}
			}
		   }
		 }
	   }
	   if(time>0&&size==0)
	   {
	   	printf("P%d  ",p_id.id);
	   }
	   else
	   {
	    if(time%10==0&&readyqueue[1].runtime!=0&&time!=0)
	    {
	    	protemp=readyqueue[0];
	    	int p;
	    	for(p=1;p<size;p++)
	    	{
	    		readyqueue[p-1]=readyqueue[p];
			}
			readyqueue[size-1]=protemp;
	    }
	     if(readyqueue[0].runtime!=0)
		 {
		 	printf("P%d  ",readyqueue[0].id);
		 	readyqueue[0].runtime--;
		 }
		 if(readyqueue[0].runtime==0&&time!=0)
		 {
		 	int y;
		 	for(y=0;y<m;y++)
		 	{
		 		if(stu[y].id==readyqueue[0].id)
		 		{
		 			stu[y].comptime=time+1;
		 			break;
				}
			}
		 	int q;
		 	for(q=1;q<size;q++)
		 	{
		 		readyqueue[q-1]=readyqueue[q];
			}
			 size--;
		 	rem_time--;
		 }
	}
		 time++;
    }
    getwttat(stu,m);
}
