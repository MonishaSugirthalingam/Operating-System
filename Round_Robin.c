#include<stdio.h>  
#include<conio.h>  
  
int main()  
{  
    // initlialize the variable name  
    int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avg_wt, avg_tat;  
    int id[100];
    printf("Total number of process in the system: ");  
    scanf("%d",&NOP);  
    y = NOP; // Assign the number of process to variable y  
    printf("Enter the Process ID,Arrival and Burst time of the Process\n");
   // Use for loop to enter the details of the process like Arrival time and the Burst Time  
   for(i=0; i<NOP; i++)  
    {  
        scanf("%d",&id[i]);
        scanf("%d", &at[i]);  
        scanf("%d", &bt[i]);  
        temp[i]=bt[i]; // store the burst time in temp array  
    }  
   // Accept the Time qunat  
    printf("Enter the Time Quantum for the process : ");  
    scanf("%d", &quant);  
   // Display the process No, burst time, Turn Around Time and the waiting time  
    printf("Process No\tBurst Time\tTurn Around Time\tWaiting Time\n");  
    for(sum=0, i = 0; y!=0; )  
    {  
        if(temp[i] <= quant && temp[i] > 0) // define the conditions   
        {  
            sum = sum + temp[i];  
            temp[i] = 0;  
            count=1;  
        }     
        else if(temp[i] > 0)  
        {  
            temp[i] = temp[i] - quant;  
            sum = sum + quant;    
        }  
        if(temp[i]==0 && count==1)  
        {  
            y--; //decrement the process no.  
            printf("%d\t\t%d\t\t%d\t\t\t%d\n", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
            wt = wt+sum-at[i]-bt[i];  
            tat = tat+sum-at[i];  
            count =0;     
        }  
        if(i==NOP-1)  
        {  
            i=0;  
        }  
        else if(at[i+1]<=sum)  
        {  
            i++;  
        }  
        else  
        {  
            i=0;  
        }  
    } 
    
   // represents the average waiting time and Turn Around time  
   avg_wt = wt * 1.0/NOP;  
   avg_tat = tat * 1.0/NOP;  
   printf("Average Turn Around Time : %f\n", avg_wt);  
   printf("Average Waiting Time : %f\n", avg_tat);  
   getch();  
   return 0;
}  