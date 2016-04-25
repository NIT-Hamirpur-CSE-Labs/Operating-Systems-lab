#include<stdio.h>


void display();
void getdata();
void waitTime();
void turnAroundTime();

int n,i, a[100],b[100];

int main()
{
    printf("***** FCFS ( FIRST COME FIRST SERVE ) SCHEDULING ******\n\n");

    getdata();
    display();
    waitTime();
    turnAroundTime();
    
}

void getdata()
{   
    char c;
    printf("Enter the number of process ");
    scanf("%d",&n);

    printf("\nDo you need to enter the arrival time of process [y/n] or [Y/N]\n");
    scanf("%s",&c);

    for (i=0; i<n; i++)
    {
          printf("Enter the %d process burst time : ",i+1);
          scanf("%d",&b[i]);
          if(c=='y' || c=='Y')
          {
                  printf("Enter the %d process arrival time : ",i+1);
                  scanf("%d",&a[i]);
          }
          else
          {
                  a[i]=0;
          }
    }
}

void display()
{
     printf("\nPROCESS\tBURST TIME\tARRIVAL TIME6\n");
     for( i=0; i<n; i++)
     {
             printf("    %d\t      %d\t      %d\n",i+1,b[i],a[i]);
     }
}

void waitTime()
{
     int w[100];
     float totalWait=0;
     w[0]=0;
     for( i=1; i<n; i++)
     {
           w[i]=b[i-1]-a[i]+w[i-1];
           totalWait=w[i]+totalWait;
     }
     printf("\nTotal Waiting time = %f",totalWait);
     printf("\nAverage Waiting time = %f",totalWait/); 
}

void turnAroundTime()
{
     int tat[100];
     float totalTat=0;
     tat[-1]=0;
     for(i=0; i<n; i++)
     {
             tat[i]=b[i]-a[i]+tat[i-1];               
             totalTat=totalTat+tat[i];
     }
     printf("\n\nTotal Turn Around Time(TAT) = %f",totalTat);
     printf("\nAverage Turn Around Time Avg.(TAT) = %f",totalTat/n);
}
