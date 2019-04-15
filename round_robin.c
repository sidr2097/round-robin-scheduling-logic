#include<stdio.h>

int main()
{
	int total,n,time,i,j,at[10],bt[10],wt[10],rem[10],flag[10];
	
	printf("Enter the total number of processes : ");
	scanf("%d",&total);
	n=total;
	
	printf("\nEnter the time slice : ");
	scanf("%d",&time);
	
	for(i=0;i<total;i++)
	{
		printf("\nEnter the arrival time for P[%d]",i+1);
		scanf("%d",&at[i]);
		printf("\nEnter the burst time for P[%d]",i+1);
		scanf("%d",&bt[i]);
		rem[i]=bt[i];
	}
	
	for(i=0;i<total;i++)
	{
		wt[i]=0;
		flag[i]=1;
	}
	
	while(total!=0)
	{
		for(i=0;i<total;i++)
		{
			if(rem[i]>=time)
			{
				for(j=0;j<total;j++)
				{
					if( (j!=i) && flag[j]==1)
					{
						wt[j]=wt[j]+time;
					}
				}
				
				rem[i]=rem[i]-time;
				if(rem[i]==0)
				{
					flag[i]=0;
					total=total-1;
				}
			}
			else
			{
				for(j=0;j<total;j++)
				{
					if( (j!=i) && (flag[j]==1) )
					{
						wt[j]=wt[j]+rem[i];
					}
				}
				rem[i]=0;
				flag[i]=0;
				total=total-1;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		wt[i]=wt[i]-at[i];
	}
	
	printf("\nProcess \t\tArrival time \t\tBurst time \t\tWaiting time\n");
	for(i=0;i<n;i++)
	{
		printf("\nP[%d] \t\t\t%d \t\t\t%d \t\t%d",i+1,at[i],bt[i],wt[i]);
	}
	return 0;
}
