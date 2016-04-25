#include<stdio.h>

struct process
{
	char name;
	int burst;
	int arrival;
	int wait;
	int turn;
	int grant;
}p[10];

int main()
{	int i,j,n,time;
	printf("enter no. of process\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	printf("enter arrival burst\n");
		scanf("%d",&p[i].arrival);
		scanf("%d",&p[i].burst);		
	}

	for(i=0;i<n;i++)
		p[i].wait=0;

	for(i=0;i<n;i++)
		p[i].turn=0;

	for(i=0;i<(n-1);i++)
		for(j=0;j<(n-1);j++)
			if(p[j].arrival>p[j+1].arrival)
			{
				char s;
				s=p[j].name;
				p[j].name=p[j+1].name;
				p[j+1].name=s;

				int c;
				c=p[j].arrival;
				p[j].arrival=p[j+1].arrival;
				p[j+1].arrival=c;

				c=p[j].burst;
				p[j].burst=p[j+1].burst;
				p[j+1].burst=c;

			}
				

	for(i=0;i<n;i++)
	printf("%c %d %d\n ",p[i].name,p[i].arrival,p[i].burst );
			
		time=0;
		i=0;


	while(1)
	{
		if(p[i].arrival<=time)
		{	
			p[i].grant=time;
			int l=p[i].burst;
			while(l!=0)
			{	
				l--;
				time++;
				printf("%d=%d time=%d  ",i,l,time );
				
			}
			printf("time=%d\n",time);
			i++;
		}
		
		if(i==n)
			break;
		
	}		
	printf("sdf\n");

	for(i=0;i<n;i++)
	{
		p[i].wait=p[i].grant-p[i].arrival;
		p[i].turn=p[i].wait+p[i].burst;
	}

	for(i=0;i<n;i++)
	printf("%c %d %d\n ",p[i].name,p[i].wait,p[i].turn );
	float avg=0;
	for(i=0;i<n;i++)
		avg=p[i].wait+avg;
	avg=avg/n;
	printf("average waiting time=%f\n",avg );
}