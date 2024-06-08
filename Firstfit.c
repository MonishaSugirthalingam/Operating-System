#include <stdio.h>
int n,m;
int blocksize[30];
int processsize[30];
void firstfit();
int main()
{
    printf("*****************************\n");
    printf("    NAME   : MONISHA.S\n");
    printf("    REG.NO : 21BCT0414\n");
    printf("    AIM    : To Impelement FirstFit\n");
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
    int flag=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(processsize[i]<blocksize[j])
            {
                blocksize[j]=blocksize[j]-processsize[i];
                printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1,processsize[i],j+1,blocksize[j]);
                flag=1;
                break;
            }
            
        }
        if(flag==0)
        {
            printf("%d\t\t\t%d\t\t\tCannot Allocate\n",i+1,processsize[i]);
        }
        flag=0;
    }
   return 0;
}
