#include<iostream>
using namespace std;
int main()
	{
		int n,ff,pf=0,i,j=0,k=0,avail;
		int p[25],f[5];
		cout<<"\n enter number of elememts in queue ";
		cin>>n;
		cout<<"\n enter number of frames ";
		cin>>ff;
		for(i=0;i<n;i++)
			{
				cin>>p[i];
			}
			for(i=0;i<ff;i++)
				f[i]=-1;
		for(i=0;i<n;i++)
		{avail=0;
			for(j=0;j<ff;j++)
			{
				if(p[i]==f[j])
				{
					avail=1;
					break;
				}
			}cout<<"\n"<<p[i]<<"\t\t";
			if(avail==0)
			{
				f[k]=p[i];
				
				for(j=0;j<ff;j++)
					cout<<f[j]<<"\t";
				cout<<"\t FAULT";
				pf++;
				k=(k+1)%ff;
				
			}

		}
		cout<<"\n number of page faults "<<pf;
		return 0;
	}