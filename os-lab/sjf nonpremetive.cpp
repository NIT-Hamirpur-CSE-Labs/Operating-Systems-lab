#include<stdio.h>

struct process
{
	char name;
	int burst;
	int arrival;
	int wait;
	int turn;
	int grant;
	int t;
}p[10];

int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i].arrival);
		scanf("%d",&p[i].burst);
		p[i].name='A'+i;

	}

	for(i=0;i<n;i++)
	{
		p[i].wait=0;
		p[i].turn=0;
		p[i].t=0;
		p[i].grant=-1;
	}
	
	for(i=0;i<(n-1);i++)
		for(j=0;j<(n-1);j++)
			if(p[j].burst>p[j+1].burst)
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
	{
		printf("%d %d\n",p[i].arrival,p[i].burst );
	}			
			int time=0,l;
			i=0;

			
	while(1)
	{	out:;
		for(i=0;i<n;i++)
		{	//l=p[i].burst;
			if(p[i].arrival<=time && p[i].grant==-1)
			{	p[i].grant=time;
				l=p[i].burst;
				while(l!=0)
				{
					l--;
					time++;
					printf("%d=%d ",i,time );
				}
				time=time+l;
				i=0;
				printf("time=%d\n",time );
				goto out;
			}
			
		}
		
	/*for(j=0;j<n;j++)
	{
		if(p[j].grant==-1)
			goto out2;
	}*/
	break;
	}	
	//out2:;	
	//printf("sdf\n");
	for(i=0;i<n;i++)
	{
		p[i].wait=p[i].grant-p[i].arrival;
		p[i].turn=p[i].wait+p[i].burst;
	}

	for(i=0;i<n;i++)
	printf("%c %d %d %d\n ",p[i].name,p[i].wait,p[i].turn,p[i].grant );
	float avg=0;
	for(i=0;i<n;i++)
		avg=p[i].wait+avg;
	avg=avg/n;
	printf("average waiting time=%f\n",avg );

}
