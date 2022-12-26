#include<stdio.h>
int main(){
    float avg_tat=0,avg_wt=0;
    int i,n;
    int table[10][3];
    printf("Enter number of processes :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter burst time of process %d : ",i+1);
        scanf("%d",&table[i][0]);
    }
    // waiting time
    table[0][1]=0;
    for(i=1;i<n;i++){
        table[i][1]=table[i-1][0]+table[i-1][1];
    }
    // for turn around time
    for(i=0;i<n;i++){
        table[i][2]=table[i][0]+table[i][1];
    }
    printf("processes    burst time    waiting time   turn around time");
    for(i=0;i<n;i++){
        printf("\np(%d)    \t%d    \t\t%d    \t\t%d",i+1,table[i][0],table[i][1],table[i][2]);
        avg_tat = avg_tat + table[i][2];
        avg_wt = avg_wt + table[i][1];
    }
    avg_tat = (float)avg_tat/n;
    avg_wt = (float)avg_wt/n;
    printf("\nAverage waiting time = %f \n Average turn around time = %f",avg_wt,avg_tat);
}