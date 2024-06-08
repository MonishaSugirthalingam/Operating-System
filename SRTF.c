#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct node 
{
    int id;
    int at;
    int bt;
};
bool burst(struct node a[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].bt==0)
        {
            count++;
        }
    }
    if(count==n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void swap(struct node *a,struct node *b)
{
    struct node temp=*a;
    *a=*b;
    *b=temp;
}
void sort(struct node a[],int n)
{
    int min;
    for(int i=0;i<n;i++)
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
    int copyID[10],copyAt[10],copyBt[10];
    printf("Enter the number of process : ");
    scanf("%d",&n);
    struct node a[100];
    printf("Enter the Process ID,Arrival Time and Burst Time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].id,&a[i].at,&a[i].bt);
    }
    //copy of id,arrival and bursttime
    for(int i=0;i<n;i++)
    {
        copyID[i]=a[i].id;
        copyAt[i]=a[i].at;
        copyBt[i]=a[i].bt;
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
    int ct[n];
    int cid[100],x=0;
    a[0].bt=a[0].bt-1;
    cid[x]=a[0].id;
    x++;
    int timeline=1;
    int count=0;
   while(!burst(a,n))
    {
        for(int i=0;i<n;i++)
        {
            if(a[i].at<=timeline && a[i].bt!=0)
            {
                swap(&a[i],&a[count]);
                count++;
            }
        }
        sort(a,count);
        a[0].bt=a[0].bt-1;
        cid[x]=a[0].id;
        x++;
        timeline++;
        count=0;
    }
    printf("Gantt Chart : ");
    for(int i=0;i<x;i++)
    {
        printf("%d ",cid[i]);
    }
    printf("\n");
    int result[100];
    result[0]=1;
    for(int i=1;i<x;i++)
    {
        result[i]=result[i-1]+1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=x-1;j>=0;j--)
        {
            if(cid[j]==i)
            {
                ct[i]=result[j];
                break;
            }
        }
    }
    int tut[10];
    //to find turn around Time
    for(int i=0;i<n;i++)
    {
        tut[i]=ct[i+1]-copyAt[i];
    }
    int wt[10];
    //to find waiting Time
    for(int i=0;i<n;i++)
    {
        wt[i]=tut[i]-copyBt[i];
    }
    printf("Process ID\tArrival Time\tBurst Time\tCompletionTime\tWaiting Time\tTurn Around Time\n\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",copyID[i],copyAt[i],copyBt[i],ct[i+1],wt[i],tut[i]);
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