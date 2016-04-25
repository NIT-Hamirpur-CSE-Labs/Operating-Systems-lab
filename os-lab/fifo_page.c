#include<stdio.h>
int main()
{
	int i,j,n,a[50],frame[10],no,k,avail,count=0;
	printf("enter the no of pages");
	scanf("%d",&n);
	printf("\nEnter the page no");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\nEnter the no of frames");
	scanf("%d",&no);
	for(i=0;i<no;i++)
	frame[i] = -1;
	j=0;
	printf("\nref string\t page frames\n");
	for(i=1;i<=n;i++)
	{
	printf("%d\t\t",a[i-1]);
	avail = 0;
		for(k=0;k<no;k++)
		
			if(frame[k]==a[i-1])
			avail = 1;
		if(avail==0)
		{
			frame[j] = a[i-1];
			j = (j+1)%no;
			count++;
			for(k=0;k<no;k++)
			printf("%d\t",frame[k]);
		}
		printf("\n");
	}
	printf("page fault is %d",count);
	return 0;
}

