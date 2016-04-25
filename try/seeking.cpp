#include<iostream>
#include<math.h>
using namespace std;
int main()
	{
		int q[100],n,seek=0,head;
		int i,j,k;
		cout<<"\n enter number of elements in the queue ";
		cin>>n;
		for(i=0;i<n;i++)
		cin>>q[i];
		for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		if(q[i]>q[j])
		swap(q[i],q[j]);
		cout<<"\n enter head position ";
		cin>>head;
		for(i=0;i<n;i++)
		if(q[i]>head)
		break;
		k=head;
		for(j=i-1;j>=0;j--)
		{
			seek+=abs(k-q[j]);
			k=q[j];
			cout<<"-->"<<q[j];
			
		}k=0;
		seek+=q[0];
		for(j=i;j<n;j++)
		{
			seek+=abs(k-q[j]);
			k=q[j];
			cout<<"-->"<<q[j];
		}
		cout<<"\n total seek time "<<seek;
		return 0;
	}
