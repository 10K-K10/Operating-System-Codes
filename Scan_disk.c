#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int crnt,temp;
    scanf("%d",&crnt);
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    int total_hm=0;
    int direction;
    float avg_head;
    int j;
    scanf("%d",&direction);
    if(direction==1)
    {
        total_hm=(199-crnt) + (199 - arr[0]);

        for(int i=0;i<n;i++)
        {
            if(crnt<=arr[i]){
                j=i;
                break;
            }
        }
        avg_head=(float)total_hm/n;
        printf("TOTAL HEAD MOVEMENTS = %d\tAVERAGE HEAD MOVEMENT = %f\tSEEK SEQUENCE\n",total_hm,avg_head);
        printf("53\t")
        for(int i=j;i<n;i++)
            printf("%d\t",arr[i]);
        printf("199\t");
        for(int i=j-1;i>=0;i--)
            printf("%d\t",arr[i]);
    }
    else{
        total_hm=(crnt-0) + arr[n-1];
        avg_head=(float)total_hm/n;
        printf("TOTAL HEAD MOVEMENTS = %d\tAVERAGE HEAD MOVEMENT = %f\tSEEK SEQUENCE\n",total_hm,avg_head);
        printf("53\t")
        for(int i=0;i<n;i++)
        {
                printf("%d\t",arr[i]);
                if(arr[i]>=crnt)
                {
                    j=i;
                    break;
                }

        }
        for(int i=j+1;i<n;i++)
            printf("%d\t",arr[i]);
    }


//    printf("Right %d \nLeft %d \n",total_hm,total_hm1);
return 0;

}
