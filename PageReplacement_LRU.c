#include <stdio.h>
#include <stdbool.h>
int frames[10];
int fcount,icount;
int inputs[50];
int h=0,m=0;
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
void miss(int index)
{
    for(int i=0;i<index;i++)
    {
        for(int j=0;j<fcount;j++)
        {
            if(inputs[i]==frames[j])
            {
                frames[j]=inputs[index];
                return;
            }
        }
    }
}
int main()
{
    printf("*****************************\n");
    printf("    NAME   : MONISHA.S\n");
    printf("    REG.NO : 21BCT0414\n");
    printf("    AIM    : To Impelement the Page Repacement Algorithm \n");
    printf("             ALGO : Least Recently Used(LRU)\n");
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
        printf("Miss ");
        frames[i]=inputs[i];
        for(int j=0;j<i+1;j++)
        {
            printf("%d ",frames[j]);
        }
        printf("\n");
    }
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
            miss(i);
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