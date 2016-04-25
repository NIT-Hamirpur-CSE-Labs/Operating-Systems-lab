#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n,i,j,wt[20],bt[20],tat[20],total=0,pos,temp;
	float awwt,awtat;
	cout<<"enter number of processes";
	cin>>n;
	cout<<"enter burst time";
	for(i=0;i<n;i++)
	cin>>bt[i];

for(i=0;i<n;i++)
{
	pos=i;
	for(j=i+1;j<n;j++)
	{
		if(bt[j]<bt[i])
		pos=j;
	}
	temp=bt[i];
	bt[i]=bt[pos];
	bt[pos]=temp;
	
}
wt[0]=0;
for(i=1;i<n;i++)
{
	wt[i]=0;
	for(j=0;j<i;j++)
	wt[i]+=bt[j];
	total+=wt[i];
}
awwt=(float) total/n;
total=0;
cout<<"process\twaiting time\tturn around time\n";
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
total+=tat[i];
	cout<<"P["<<i<<"]"<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
	cout<<"\n";
}
cout<<"Gantt Chart:";
for(i=0;i<n;i++)
{
	cout<<"P["<<i<<"]"<<"--->"<<wt[i]<<"--->";
}
awtat=(float) total/n;
cout<<"\naverage waiting time"<<awwt;
cout<<"\naverage turn around time"<<awtat;
return 0;
}
