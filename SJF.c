#include <stdio.h>
#include <string.h>

struct node 
{
    int id;
    int at;
    int bt;
};
void swap(struct node *a,struct node *b)
{
    struct node temp=*a;
    *a=*b;
    *b=temp;
}
void sort(struct node a[],int m,int n)
{
    int min;
    for(int i=m;i<n;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j].bt<a[min].bt)
            {
                min=j;
            }
        }
        swap(&a[min],&a[i]);
    }
}
int main()
{
    int n,i;
    printf("Enter the number of process : ");
    scanf("%d",&n);
    struct node a[100];
    printf("Enter the Process ID,Arrival Time and Burst Time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].id,&a[i].at,&a[i].bt);
    }
    int min;
    for(i=0;i<n;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j].at<a[min].at)
            {
                min=j;
            }
        }
        swap(&a[min],&a[i]);
    }
    int ct[10],cid[10];
    ct[0]=a[0].at+a[0].bt;
    cid[0]=a[0].id;
    int stop=1;
    int count=1;
    while(stop!=n)
    {
        
        for(int i=stop;i<n;i++)
        {
            if(a[i].at<ct[stop-1])
            {
                swap(&a[i],&a[count]);
                count++;
            }
        }
        sort(a,stop,count);
        ct[stop]=a[stop].bt+ct[stop-1];
         count=stop+1;
         stop++;
        
    }
    int tut[10];
    //to find turn around Time
    for(int i=0;i<n;i++)
    {
        tut[i]=ct[i]-a[i].at;
    }
    int wt[10];
    //to find waiting Time
    for(int i=0;i<n;i++)
    {
        wt[i]=tut[i]-a[i].bt;
    }
    printf("Process ID\tArrival Time\tBurst Time\tCompletionTime\tWaiting Time\tTurn Around Time\n\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",a[i].id,a[i].at,a[i].bt,ct[i],wt[i],tut[i]);
    }
    //to find Average Waiting Time
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
        sum1=sum1+wt[i];
        sum2=sum2+tut[i];
    }
    float avg_wt=sum1/(float)n;
    float avg_tut=sum2/(float)n;
    printf("Average Waiting Time is %f\n",avg_wt);
    printf("Average Turn Around Time is %f\n",avg_tut);
}