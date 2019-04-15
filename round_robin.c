#include<stdio.h>

int main()
{
	int total,n,time,i,j,at[10],bt[10],wt[10],rem[10],flag[10];
	//n=total=total number of processes		at=arrival tiume		bt=burst time		wt=waiting time		rem=remaining time		
	
	//Entry for processes
	printf("Enter the total number of processes : ");
	scanf("%d",&total);
	n=total;
	
	//Entry for time-slice or time-quantum
	printf("\nEnter the time slice : ");
	scanf("%d",&time);
	
	//Details for each process
	for(i=0;i<total;i++)
	{
		printf("\nEnter the arrival time for P[%d] : ",i+1);
		scanf("%d",&at[i]);
		printf("\nEnter the burst time for P[%d] : ",i+1);
		scanf("%d",&bt[i]);
		rem[i]=bt[i];
		
		wt[i]=0;		//Initial waiting time for each process is 0
		flag[i]=1;		//flag for every process is 1
	}
	
	
	
	while(total!=0)		//untill number of left processes becomes 0
	{
		for(i=0;i<total;i++)
		{
			if(rem[i]>=time)		
			{
				for(j=0;j<total;j++)
				{
					if( (j!=i) && (flag[j]==1) && (rem[j]!=0) )
					{
						wt[j]=wt[j]+time;		//time slice added to waiting time for every process
					}
				}
				
				rem[i]=rem[i]-time;		//remaining time for process left after going back in queue
				
				if(rem[i]==0)		//if remaining time becomes 0
				{
					flag[i]=0;		//set flag=0 to not use the process
					total=total-1;		//decrease the number of processes  by 1
				}
			}
			else
			{
				for(j=0;j<total;j++)
				{
					if( (j!=i) && (flag[j]==1) && (rem[j]!=0) )
					{
						wt[j]=wt[j]+rem[i];		//time taken by P[i] is added to waiting time for every process
					}
				}
				rem[i]=0;
				
				flag[i]=0;		//set flag=0 to not use the process
				
				total=total-1;		//decrease the number of processes  by 1
			}
		}
	}
	
	
	//removing time added to waiting time before arrival of process
	for(i=0;i<n;i++)
	{
		wt[i]=wt[i]-at[i];
	}
	
	
	//Printing deatils on the screen
	printf("\nProcess \t\tArrival time \t\tBurst time \t\tWaiting time\n");
	for(i=0;i<n;i++)
	{
		printf("\nP[%d] \t\t\t%d \t\t\t%d \t\t%d",i+1,at[i],bt[i],wt[i]);
	}
	
	return 0;
}
