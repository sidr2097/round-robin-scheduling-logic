#include<stdio.h>

int main()
{
	//Variable Declarations
	int i,j,n,time,total,bt[10],at[10],flag[10];		//n = total processes		bt = burst time		at = arrival time
	int wt[10],ta[10],lt[10];		//wt = wait time		ta = turn around time		lt = time left from burst time
	
	//Taking number of processes from user
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	total=n;
	
	//Time quatum input
	printf("\nEnter the time quantum : ");
	scanf("%d",&time);
	
	//Details of each process
	for(i=0;i<n;i++)
	{
		printf("\nEnter the arrival time for P[%d] : ",i+1);
		scanf("%d",&at[i]);
		printf("\nEnter the burst time for P[%d] : ",i+1);
		scanf("%d",&bt[i]);
		lt[i]=bt[i];
	}
	
	//Setting flags for each process
	for(i=0;i<n;i++)
	{
		flag[i]=1;
		wt[i]=0;
	}
	
	while(n!=0)
	{
		for(i=0;i<n;i++)
		{
			if(lt[i]>=time)
			{
				for(j=0;j<n;i++)
				{
					if( (i!=j) && (flag[i]==1) && (lt[i]==0) )
					{
						wt[j]=wt[j]+time;
					}
				
					lt[i]=lt[i]-time;
				
					if(lt[i]==0);
					{
						flag[i]=0;
						n=n-1;
					}
				
				}
			}
			else
			{
				for(j=0;j<n;j++)
				{
					if( (i!=j) && (flag[i]==1) && (lt[i]==0) )
					{
						wt[j]=wt[j]+lt[i];
					}
				
					lt[i]=0;
					n=n-1;
					flag[i]=0;
				}
			}
		}
	}
	printf("\nProcess \t\tArrival time \t\tBurst time \t\tWaiting time\n");
	for(i=0;i<total;i++)
	{
		printf("\nP[%d] \t\t\t%d \t\t\t%d \t\t\t%d",i+1,at[i],bt[i],wt[i]);
	}
	printf("Hello");
}
