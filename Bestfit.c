#include <stdio.h>
#include <stdbool.h>
#define INT_MAX 20000;
int n,m;
int blocksize[30];
int processsize[30];
int bestfit(int);
int main()
{
   printf("*****************************\n");
   printf("    NAME   : MONISHA.S\n");
   printf("    REG.NO : 21BCT0414\n");
   printf("    AIM    : To Impelement BestFit\n");
   printf("*****************************\n\n");
   printf("Enter the number of free Blocks : ");
   scanf("%d",&n);
   printf("Enter the number of Process : ");
   scanf("%d",&m);
   printf("Enter the free Blocksizes : ");
   for(int i=0;i<n;i++)
   {
       scanf("%d",&blocksize[i]);
   }
    printf("Enter the Process Size : ");
   for(int i=0;i<m;i++)
   {
       scanf("%d",&processsize[i]);
   }
   printf("\nProcess\t\t\tProcess Size\t\tBlock No\t\tRemaining Block Size\n");
   for(int i=0;i<m;i++)
   {
       int r=bestfit(i);
       if(r>=0)
       {
            blocksize[r]=blocksize[r]-processsize[i];
            printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1,processsize[i],r+1,blocksize[r]);
       }
       else
       {
           printf("%d\t\t\t%d\t\t\tCannot Allocate\n",i+1,processsize[i]);
       }
   }
   return 0;
}
int bestfit(int i)
{
    int min=INT_MAX;
    int b=0;
    int temp;
    int f=0;
    for(int j=0;j<n;j++)
    {
        temp=blocksize[j]-processsize[i];
        if(temp<=min && processsize[i]<=blocksize[j] && temp>=0)
        {
            min=temp;
            f=1;
            b=j;
        }
    }
    if(f==1)
    {
        return b;
    }
    else
    {
        return -1;
    }
}