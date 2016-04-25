#include<iostream>

using namespace std;

int main()
{
  int n,bt[20],wt[20],trt[20],avwt=0,avtrt=0,i,j;

   cout<<"enter no of process:";
   cin>>n;

   cout<<"enter process burst time:";
   for(i=0;i<n;i++)
   {
    cout<<"P["<<i+1<<"]";
    cin>>bt[i];
   }
   
    wt[0]=0;
   
   for(i=1;i<n;i++)
   {
    wt[i]=0;
    for(j=0;j<i;j++)
    wt[i]+=bt[j];
   }
  
   cout<<"Process BurstTime WaitingTimet TurnaroundTime";
  
   for(i=0;i<n;i++)
   {
    trt[i]=bt[i]+wt[i];
    avwt+=wt[i];
    avtrt+=trt[i];

   cout<<"P["<<i+1<<"]"<<"  "<<bt[i]<<"  "<<wt[i]<<"  "<<trt[i];
   }
  
    avwt/=n;
    avtrt/=n;
    cout<<"average waiting time:"<<avwt;
    cout<<"average turnaround time:"<<avtrt;

  return 0;


} 













  


