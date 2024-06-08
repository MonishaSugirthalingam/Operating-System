#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
void isomorphic_str(char a[],char b[])
{
    char unique[10];
    int count=0;
    if(strlen(a)==strlen(b))
    {
        //Finding the unique values in string
        unique[count]=a[0];
        count++;
        int flag=0,check=0;;
        for(int i=1;i<strlen(a);i++)
        {
            for(int j=0;j<count;j++)
            {
                if(a[i]==unique[j])
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                unique[count]=a[i];
                count++;
            }
            flag=0;
        }
        //One to one mapping
        char map[10];
        for(int i=0;i<count;i++)
        {
            for(int j=0;j<strlen(a);j++)
            {
                if(unique[i]==a[j])
                {
                    map[i]=b[j];
                }
            }
        }
        //checking of one to one mapping
        for(int i=0;i<count;i++)
        {
            for(int j=0;j<strlen(a);j++)
            {
                if(unique[i]==a[j])
                {
                    if(map[i]!=b[j])
                    {
                        printf("Given String is Not a isomorphic each other\n");
                        check=1;
                        break;
                    }
                }
            }
        }
        if(check==0)
        {
        printf("Given String is Isomorphic each other\n");
        }
    }
    else
    {
        printf("Given String is Isomorphic each other\n");
    }
}
void swap(char *a,char *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort(char a[])
{
    int temp;
        for(int i=0;i<strlen(a);i++)
        {
            int min=i;
            for(int j=i+1;j<strlen(a);j++)
            {
                if(a[j]<a[min])
                {
                    min=j;
                }
            }
            swap(&a[i],&a[min]);
        }
}
void anagrams_str(char a[],char b[])
{
    if(strlen(a)==strlen(b))
    {
        sort(a);
        sort(b);
        if(strcmp(a,b)==0)
        {
            printf("Given strings are Anagrams\n");
        }
        else
        {
            printf("Given Strings are Not Anagram\n");
        }
    }
    else
    {
        printf("Given Strings are Not Anagram\n");
    }
}
int main()
{
    
    char str1[20];
    char str2[20];
    printf("Enter the String1 : ");
    scanf("%s",str1);
    printf("Enter the String2 : ");
    scanf("%s",str2);
    pid_t x;
    x=fork();
    if(x==-1)
    {
        printf("Child process creation is failed\n");
    }
    if(x==0) //two input strings are Isomorphic strings.
    {
        printf("Child Process is Running..Process id is %d\n",getpid());
        isomorphic_str(str1,str2);
    }
    if(x>0) //two input strings are Anagrams.
    {
        printf("Parent Process is Running..Process id is %d\n",getpid());
       anagrams_str(str1,str2);
    }
    return 0;
}