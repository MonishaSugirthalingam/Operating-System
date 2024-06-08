#include <stdio.h>
#include <string.h>

struct node 
{
    int id;
    int at;
    int bt;
    int pt;
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
            if(a[j].pt<a[min].pt)
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
    printf("Enter the Process ID,Priority Time,Arrival Time and Burst Time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i].id,&a[i].pt,&a[i].at,&a[i].bt);
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
    int no=0;
    int x=0,idle[10];
    while(stop!=n)
    {
        
        for(int i=stop;i<n;i++)
        {
            if(a[i].at<=ct[stop-1])
            {
                no=1;
                swap(&a[i],&a[count]);
                count++;
            }
        }
        
        if(no==0)
        {
            ct[stop-1]=ct[stop-1]+1;
            idle[x]=a[stop-1].id;
            x++;
        }
        else
        {
        sort(a,stop,count);
        ct[stop]=a[stop].bt+ct[stop-1];
        /*printf("%d %d %d\n\n",stop,count,ct[stop]);
         for(int i=0;i<n;i++)
         {
        printf("%d %d %d\n",a[i].id,a[i].at,a[i].bt);
         }
         printf("\n\n");*/
         count=stop+1;
         stop++;
        }
        no=0;
    }
    int tut[10];
    int found=0;
    //to find turn around Time
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<x;j++)
        {
            if(a[i].id==idle[j])
            {
                found=1;
            }
        }
        if(found!=1)
        {
            tut[i]=ct[i]-a[i].at;
        }
        else
        {
            tut[i]=ct[i]-a[i].at-1;
        }
        found=0;
    }
    int wt[10];
    //to find waiting Time
    for(int i=0;i<n;i++)
    {
        wt[i]=tut[i]-a[i].bt;
    }
    printf("Process ID\tPriority Time\tArrival Time\tBurst Time\tCompletionTime\tWaiting Time\tTurn Around Time\n\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",a[i].id,a[i].pt,a[i].at,a[i].bt,ct[i],wt[i],tut[i]);
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