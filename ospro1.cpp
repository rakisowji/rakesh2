#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void waiting_time1(int process[],int no_of_processes,int burst_time[],int waiting_time[],int quantum)
{
	int remaining_burst_time[no_of_processes],j=0;
	for(int i=0;i<no_of_processes;i++)
	remaining_burst_time[i]=burst_time[i];
	int t=0;
	while(1)
	{
		bool ok = true;
		for(int i=0;i < no_of_processes;i++)
        {
        	if (remaining_burst_time[i] > 0)
            {
                ok = false; 
 
                if (remaining_burst_time[i] > quantum)
                {
                    t += quantum;
                    remaining_burst_time[i]=remaining_burst_time[i]-quantum;
                }
            else
                {
                    t = t + remaining_burst_time[i];
                    j= t-burst_time[i];
                    waiting_time[i]=j;
                    remaining_burst_time[i] = 0;
                }
            }
        }
        if (ok == true)
          break;
    }
}
void turnaroundtime(int process[], int no_of_processes,
                        int burst_time[], int waiting_time[], int tat[])
{
    for (int i = 0;i<no_of_processes; i++)
        tat[i] = burst_time[i] + waiting_time[i];
}
void avgtime(int process[], int no_of_processes, int burst_time[],
                                     int quantum)
{
    int waiting_time[no_of_processes], tat[no_of_processes], total_wt = 0, total_tat = 0;
    waiting_time1(process, no_of_processes,burst_time, waiting_time, quantum);
    printf("\n\n");
    turnaroundtime(process, no_of_processes, burst_time, waiting_time, tat);
    printf("Process\t\t\t""Burst_time\t\t\t""Waiting_time \t\t\t""turn around time\n");
    for (int i=0; i<no_of_processes; i++)
    {
        total_wt = total_wt + waiting_time[i];
        total_tat = total_tat + tat[i];
       printf("%d\t\t%d\t\t%d\t\t%d\n\n",i+1,burst_time[i],waiting_time[i],tat[i]);
    }
 
    printf("Average waiting time:"); 
         float n=(float)total_wt / (float)no_of_processes;
         printf("%f\n",n);
   printf("Average turn around time:");
       float f= (float)total_tat / (float)no_of_processes;
       printf("%f\n",f);
}
int main()
{
    int process[0];
	int o;
    printf("Enter the number of processes required:\n");
    scanf("%d",&o);
    for(int i=0;i<o;i++)
    {
    	scanf("%d",&process[i]);
	}
    int n = sizeof process / sizeof process[0];
    int burst_time[o];
    printf("enter the burst time for each process:\n");
    for(int i=0;i<o;i++)
    {
      scanf("%d",&burst_time[i]);
    }
    int quantum,q;
    printf("\nEnter the Time quantum:");
    scanf("%d",&quantum);
    while(1)
    {
    	printf("enter the option:");
    	printf("1)AVerage time:\n");
    	printf("2)exit()");
    	scanf("%d",&q);
    	switch(q)
    	{
    		case 1:
    			   {
    			   	avgtime(process,n,burst_time,quantum);
    			   	break;
				   }
			case 2:
				   {
				   	exit(1);
				   	break;
				   }
		}
	}
}

