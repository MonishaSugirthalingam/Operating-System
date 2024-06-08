#include <stdio.h>
#include <stdbool.h>
int frames[10];
int fcount,icount;
int inputs[50];
int h=0,m=0;
int replace=0;
bool hit(int n)
{
    for(int i=0;i<fcount;i++)
    {
        if(n==frames[i])
        {
            return true;
        }
    }
    return false;
}
void miss(int n)
{
    if(replace==fcount)
    {
        replace=0;
    }
    frames[replace]=n;
    replace++;
}
int main()
{
    printf("*****************************\n");
    printf("    NAME   : MONISHA.S\n");
    printf("    REG.NO : 21BCT0414\n");
    printf("    AIM    : To Impelement the Page Repacement Algorithm(FIFO) \n");
    printf("*****************************\n\n");
    printf("Enter the total number of inputs : ");
    scanf("%d",&icount);
    printf("Enter the total number of frames : ");
    scanf("%d",&fcount);
    printf("Enter the inputs one by one : ");
    for(int i=0;i<icount;i++)
    {
        scanf("%d",&inputs[i]);
    }
    for(int i=0;i<fcount;i++)
    {
        frames[i]=inputs[i];
    }
    printf("Miss %d\n",frames[0]);
    printf("Miss %d %d\n",frames[0],frames[1]);
    printf("Miss %d %d %d\n",frames[0],frames[1],frames[2]);
    m=fcount;
    for(int i=fcount;i<icount;i++)
    {
        if(hit(inputs[i]))
        {
            h++;
            printf("Hit  ");
            for(int k=0;k<fcount;k++)
            {
                printf("%d ",frames[k]);
            }
            printf("\n");
        }
        else
        {
            miss(inputs[i]);
            m++;
            printf("Miss ");
            for(int k=0;k<fcount;k++)
            {
                printf("%d ",frames[k]);
            }
            printf("\n");
        }
    }
    printf("Page Fault : %d\nNo.Of Hits : %d\n",m,h);
    return 0;
}