//SJF preemptive
#include<iostream>
using namespace std;
struct pr
	{
	int bt,bbt,tat,wt,p,at,c,st;
	};
void input(pr p[],int i)
	{
	cout<<"\n p["<<i+1<<"]";
	cout<<"\n burst time ";
	
	cin>>p[i].bt;
	cout<<"\n arrival time ";
	cin>>p[i].at;
	p[i].bbt=p[i].bt;
	p[i].wt=0;
	p[i].p=i+1;
	p[i].c=0;
	}
void sorta(pr p[],int i)
	{
	int k = 0,j;
     	pr temp;
     	for (k = 0; k<i-1; k++)
     	{
          for (j = k+1; j<i; j++)
          {
           if(p[k].at > p[j].at)
                   {
               temp = p[k];
               p[k] = p[j];
               p[j] = temp;
               }
          }
    	 }
	}	
void sortb(pr p[],int i)
	{
	int k = 0, j;
     	pr temp;
     	for (k = 0; k<i-1; k++)
     	{
          for (j = k+1; j<i; j++)
          {
           if(p[k].bbt > p[j].bbt)
             {
               temp = p[k];
               p[k] = p[j];
               p[j] = temp;
               }
          }
    	 }
	}
int main()
	{
	
	int n,i,j,aw=0,at=0,k=1,sum=0,x,g=0,v=0;
	pr p[50],q[50];
	cout<<"\n enter total number of processes ";
	cin>>n;
	for(i=0;i<n;i++)
	{
	input(p,i);
	}
	
		sorta(p,n);
	cout<<"Gantt Chart";
		for(i=0;i<n;i++)
			{
			sum+=p[i].bt;
			}
		for(x=0;x<sum;x++)
			{
			v=0;
			for(g=0;g<n;g++)
			{if(p[g].at<=x&&p[g].bbt!=0)
				{q[v++]=p[g];
			
				}
			}
			sortb(q,v);
			q[0].bbt--;
cout<<q[0].p<<" ";
			for(int f=1;f<v;f++)
			{
			q[f].wt++;
			for(i=0;i<v;i++)
			{
				for(int a=0;a<n;a++)
				{
				if(q[i].p==p[a].p)
				p[a]=q[i];
			}
			}
		}
		}
	for(i=0;i<n;i++)
	{
	p[i].tat=p[i].wt+p[i].bt;
	aw+=p[i].wt;
	at+=p[i].tat;
	}	
	cout<<"\n process        burst  waiting  turn around ";
	for(i=0;i<n;i++)
	{	
	cout<<"\n process "<<p[i].p<<"\t"<<p[i].bt<<"\t"<<p[i].wt<<"\t"<<p[i].tat;
	}
	aw=aw/i;
	at=at/i;
	cout<<"\n average waiting time "<<aw;
	cout<<"\n average turn around time "<<at;
	return 0;
	}
