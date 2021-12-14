#include<stdio.h>
#include<stdbool.h>
struct process{
    int pid;
    int at,bt,ct,tt,wt,rt;
    int start_time;
}ps[100];

int main()
{
int n;
scanf("%d",&n);
bool iscomp[n];
for(int i=0;i<n;++i)
    iscomp[i]=false;
for(int i=0;i<n;i++)
{
    scanf("%d",&ps[i].at);
}
for(int i=0;i<n;i++)
    scanf("%d",&ps[i].bt);
int c_t=0,comp=0;
float totalct=0,totaltt=0,totalwt=0,totalrt=0;
while(comp!=n)
{
    int min_index=-1, minimum=100000;
    for(int i=0;i<n;i++)
    {
        if(ps[i].at<=c_t && iscomp[i]!=true)
        {
            if(ps[i].bt<minimum){
                minimum=ps[i].bt;
                min_index=i;
            }
            if(ps[i].bt==minimum){
                if(ps[i].at<ps[min_index].at){
                    minimum=ps[i].bt;
                    min_index=i;
                }
            }

        }

    }
    if(min_index==-1)
        c_t++;
    else{
        ps[min_index].start_time=c_t;
        ps[min_index].ct=ps[min_index].start_time + ps[min_index].bt;
        ps[min_index].tt=ps[min_index].ct - ps[min_index].at;
        ps[min_index].wt=ps[min_index].tt - ps[min_index].bt;
        ps[min_index].rt=ps[min_index].wt;
        c_t+=ps[min_index].bt;
        iscomp[min_index]=true;
    totaltt+=ps[min_index].tt;
    totalct+=ps[min_index].ct;
    totalwt+=ps[min_index].wt;
    totalrt+=ps[min_index].rt;
    comp++;
    }

}
float avg_tt= (float)totaltt/n;
float avg_ct= (float)totalct/n;
float avg_wt= (float)totalwt/n;
float avg_rt= (float)totalrt/n;


printf("C = %f\t T = %f\t W = %f",avg_ct,avg_tt,avg_wt);
return 0;
}
