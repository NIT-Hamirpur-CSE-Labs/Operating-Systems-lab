#include<iostream>
using namespace std;
int main()
	{
	int n,ff,pf=0,i,j=0,k=0,avail;
		int p[25],f[5],si,sj,sk,svalue,count[25],stack[25],top=0;
		cout<<"\n enter number of elememts in queue ";
		cin>>n;
		cout<<"\n enter number of frames ";
		cin>>ff;
		for(i=0;i<n;i++)
			{
				cin>>p[i];
				count[i]=0;
			}
			for(i=0;i<ff;i++)
				f[i]=-1;
		
		for(i=0;i<n;i++)
		{avail=0;
			for(j=0;j<ff;j++)
			{//if data is available
				if(p[i]==f[j])
				{
					avail=1;
					
					//find in stack
					for(sj=0;sj<top;sj++)
					{
						if(stack[sj]==p[i])
							break;
					}
					for(sk=sj;sk<top-1;sk++)
					{
						stack[sk]=stack[sk+1];
					}
					stack[top-1]=p[i];
					break;
				}
			}cout<<"\n"<<p[i]<<"\t\t";
			



			if(avail==0)
			{if(f[k]==-1)
				{
					f[k]=p[i];
					k=(k+1)%ff;
					stack[top++]=p[i];
					for(j=0;j<ff;j++)
					cout<<f[j]<<"\t";
				}
				



				else
				{

				
				for(si=0;si<top;si++)
				{svalue=stack[si];
				for(j=0;j<ff;j++)
				{
					if(svalue==f[j])
					{
						goto nine;
					}
				}

				}
				nine:
				f[j]=p[i];
					for(sk=si;sk<top-1;sk++)
					{
						stack[sk]=stack[sk+1];
					}
					stack[top-1]=p[i];
				for(j=0;j<ff;j++)
					cout<<f[j]<<"\t";
				cout<<"\t FAULT";
				pf++;
			}

		}}
		cout<<"\n number of page faults "<<pf;
		return 0;
	
	}