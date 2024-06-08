#include <stdio.h>
#include <stdbool.h>
struct banker
{
    int a;
    int b;
    int c;
};

struct banker max[10];
struct banker allocation[10];
struct banker need[10];
struct banker work;
int n;
bool finish[10];

bool finish_check()
{
    for(int i=0;i<n;i++)
    {
        if(finish[i]==false)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int x,y,z;
    int x1,y1,z1;
    printf("Enter the no of process : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        finish[i]=false;
    }
    //allocation values
    printf("Enter the Allocation value of each resourse for each process\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&allocation[i].a,&allocation[i].b,&allocation[i].c);
    }
    printf("Enter the Max value of each resourse for each process\n");
    //max values
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&max[i].a,&max[i].b,&max[i].c);
    }
    printf("Enter the Need value of each resourse for each process\n");
    //need values
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&need[i].a,&need[i].b,&need[i].c);
    }
    printf("Enter the Total Size of Each Resourses\n");
    //Resousre a,b and c size
    scanf("%d%d%d",&x,&y,&z);
    printf("Enter the Total allocation sixe of each resourses\n");
    //total alloaction for each resourse
    scanf("%d%d%d",&x1,&y1,&z1);
    work.a=x-x1;
    work.b=y-y1;
    work.c=z-z1;
    int safe_seq[10];
    int count=0;
    while(finish_check()!=true)
    {
        for(int i=0;i<n;i++)
        {
            if(finish[i]==false && (need[i].a<=work.a && need[i].b<=work.b && need[i].c<=work.c))
            {
                work.a=work.a+allocation[i].a;
                work.b=work.b+allocation[i].b;
                work.c=work.c+allocation[i].c;
                finish[i]=true;
                printf("Safe Sequence is : %d\n",i);
                safe_seq[count]=i;
                printf("Works %d %d %d\n",work.a,work.b,work.c);
                count++;
            }
        }
    }
    return 0;
}
