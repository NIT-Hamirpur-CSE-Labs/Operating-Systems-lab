#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,total;
float avg_wt,avg_tat;
cout<<"enter total number of process";
cin>>n;
vector<int>bt(n);
vector<int>wt(n);
vector<int>tat(n);

for(int i=0;i<n;i++)
cin>>bt[i];
sort(bt.begin(),bt.end());
wt[0]=0;//
for(int i=1;i<n;i++)
{
wt[i]=0;
for(int j=0;j<i;j++)
{
wt[i]+=bt[j];
total+=wt[i];
}
}
avg_wt=(float)total/n;
total=0;
for(int i=0;i<n;i++)
{
tat[i]+=bt[i]+wt[i];
total+=tat[i];
}
avg_tat=(float)total/n;
printf("%f",avg_wt);
printf("%f",avg_tat);


}
