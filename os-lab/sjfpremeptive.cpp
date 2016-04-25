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
		p[i].t=p[i].burst;
		p[i].name='A'+i;
	}

	for(i=0;i<n;i++)
	{
		p[i].wait=0;
		p[i].turn=0;
		//p[i].grant=-1;
	}


//for(i=0;i<n;i++)
//	printf("%c %d %d\n",p[i].name,p[i].arrival,p[i].burst );
int l,time=0,k[10];

printf("Gant chart\n");

while(1)
{	out:;
	int z=0;
	
	for(j=0;j<(n);j++)
	{	
		if(p[j].arrival<=time && p[j].t!=0)
			{k[z++]=j;
			}		
	}

	int in;
	l=99999;

	for(i=0;i<z;i++)
	{
		if(l>p[k[i]].t)
		{	
			l=p[k[i]].t;
			
			in=k[i];
		}
	}

	time++;
	p[in].t--;
	//printf("%d",in );

	for(i=0;i<z;i++)
	{	
		if(k[i]!=in)
		{
			p[k[i]].wait++;
			//printf("s\n");
		}
	}

	for(i=0;i<n;i++)
	{
		if(p[i].t!=0)
			goto out;
	}
	//printf("l=%d\n",l );
	
	

	break;
}
float avg1,avg2;
for(i=0;i<n;i++)
	p[i].turn=p[i].wait+p[i].burst;

for(i=0;i<n;i++)
	printf("\n%c %d %d",p[i].name,p[i].wait,p[i].turn );

for(i=0;i<n;i++)
{
	avg1=avg1+p[i].wait;
	avg2=avg2+p[i].turn;
}

avg2=avg2/n;
avg1=avg1/n;

printf("\naverage waiting time=%f",avg1);
printf("\naverage turn around time=%f\n",avg2);
}
