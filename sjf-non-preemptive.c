//shortest job first non preemptive
#include<stdio.h>
#include<string.h>
void main()
{
    int i,j,n,Bt[10],wt[10],At[10],Tt=0;
    char c[10][10],pn[10][10],s[10];
    int z[50];
    float Twt=0.0,Awt;
    int w=0,temp,t;
    
    printf("Enter no. of processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the Burst time for Process %d :",i+1);
        scanf("%d",&Bt[i]);
        printf("Enter the Arrival time for Process %d :",i+1);
        scanf("%d",&At[i]);
        s[i]='T';
        Tt+=Bt[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=2;j<n;j++)
        {
            if(Bt[j-1]>Bt[j])
            {
                temp=Bt[j];
                Bt[j]=Bt[j-1];
                Bt[j-1]=temp;
                temp=At[j];
                At[j]=At[j-1];
                At[j-1]=temp;
                strcpy(c[j-1],pn[j-1]);
                strcpy(pn[j-1],pn[j]);
                strcpy(pn[j],c[j-1]);
            }
        }
    }
    wt[0]=0;
    z[0]=0;
    w+=Bt[0];
    t=w;
    s[0]='F';
    while(w<Tt)
    {
        i=1;
        while(i<=n)
        {
            if(s[i]=='T' && At[i]<=t)
            {
                z[i]=w;
                wt[i]=w-At[i];
                s[i]='F';
                w+=Bt[i];
                t=w;
                i=1;
            }
            else
                i++;
        }
    }
    printf("\nProcess   \tBurst time\tArrival time \tWaiting time\n");
    
    for(i=0;i<n;i++)
        printf("\nProcess%d\t\t%d\t\t%d\t\t%d",i+1,Bt[i],At[i],wt[i]);
    
    /* printf("\n\n Gannt Chart : \n");
    for(i=0;i<n;i++)
        printf("%4d",z[i]); */
    for(i=0;i<n;i++)
        Twt+=wt[i];
    printf("\n\nTotal waiting Time : %f \t",Twt);
    Awt=Twt/n;
    printf("\nAverage waiting Time :  %f\n\n",Awt);
    
}