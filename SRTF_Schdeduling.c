#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct process{
    int pid;
    int at,bt,ct,tt,wt,rt,start_time;
}ps[100];
int main()
{

    int n;
    scanf("%d",&n);
    int bt_rem[n];
    bool iscomp[n];
    int sum_tt=0,sum_wt=0,sum_rt=0;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&ps[i].at);
        ps[i].pid=i;
        iscomp[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ps[i].bt);
        bt_rem[i]=ps[i].bt;
    }
    int comp=0,c_t=0;
    while(comp!=n)
    {
        int min_index=-1,minimum=100000;
        for(int i=0;i<n;i++){
            if(ps[i].at<=c_t && iscomp[i]!=true){
                if(bt_rem[i]<minimum){
                    minimum=bt_rem[i];
                    min_index=i;
                }
                if(bt_rem[min_index]==minimum){
                    if(ps[i].at<ps[min_index].at){
                        minimum=bt_rem[i];
                        min_index=i;
                    }
                }
            }
        }
        if(min_index==-1)
            c_t++;
        else{

            if(bt_rem[min_index]==ps[min_index].bt){
                ps[min_index].start_time=c_t;
            }
            bt_rem[min_index]-=1;
            c_t++;
            if(bt_rem[min_index]==0){
                ps[min_index].ct=c_t;
                ps[min_index].tt=ps[min_index].ct-ps[min_index].at;
                ps[min_index].wt=ps[min_index].tt-ps[min_index].bt;
                ps[min_index].rt=ps[min_index].start_time-ps[min_index].at;

                sum_tt+=ps[min_index].tt;
                sum_wt+=ps[min_index].wt;
                sum_rt+=ps[min_index].rt;
                iscomp[min_index]=true;
                comp++;
            }
        }
    }
float avg_tt=(float)sum_tt/n;
float avg_wt=(float)sum_wt/n;
float avg_rt=(float)sum_rt/n;
printf("TT = %.2f\tWT = %.2f]t RT = %.2f",avg_tt,avg_wt,avg_rt);
return 0;
}
