#include<iostream>
using namespace std;
struct pr
	{
		int rt,at,wt,bt,c,tat,p,id;
	};
int main()
	{
		int n,i,j,s=0,q[50],top=0,xx=-1;
		pr p[50];
		cout<<"\n enter number of processes ";
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>p[i].at;
			cin>>p[i].bt;
			cin>>p[i].p;
			p[i].wt=0;
			s+=p[i].bt;
			p[i].rt=p[i].bt;
			p[i].wt=0;			
		}
		
		for(int t=0;t<=s;t++)
			{j=0;
				for(i=0;i<n;i++)
				{
					if(p[i].rt!=0&&p[i].at<=t)
						{
							q[j++]=i;
						}
				}
				int x;
				x=q[0];
				int min=p[x].p,k;
				k=q[0];
				for(i=0;i<j;i++)
				{x=q[i];
					if(p[x].p<min)
					{
					min=p[x].p;
					k=q[i];
				}
			}p[k].rt--;
			for(i=0;i<n;i++)
			{
				if(i!=k)
				{
					p[k].wt++;
				}
			}
			if(xx!=k)
			cout<<k<<"("<<t<<")"<<"-->";
			
				xx=k;
			}
	}
