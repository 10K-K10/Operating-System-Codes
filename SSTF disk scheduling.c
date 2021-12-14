#include<stdio.h>
#include<stdbool.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int init;
    scanf("%d",&init);
    int totalheadmovement=0;
    int d,count=0;
    while(count!=n){
        int min=1000,index;
        for(int i=0;i<n;i++){
            d=abs(arr[i]-init);
            if(d<min){
                min=d;
                index=i;
            }

        }
        totalheadmovement+=min;
        count++;
        init=arr[index];
        arr[index]=1000;

    }
    printf("\n%d",totalheadmovement);
    return 0;
}
