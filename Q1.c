 
int main()
{
    int pid[20];
    int bt[20];
    int wt[20];
    int tat[20];
    int n,i,j;
    
    printf("Enter No. of process");
    scanf("%d",&n);
    
    printf("Enter the Process Id in proper sequence: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
    }
    printf("Enter the BUrst Time in proper sequence: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    printf("\n\nCalulating the waiting time for every process");
    for(i=1;i<n;i++)
    {
      wt[i]=0;
      for(j=0;j<i;j++)
      {
       wt[i]=wt[i]+bt[j];
      }
    }
    printf("\n\nCalulating the turn around time for every process");
    for(i=0;i<n;i++)
    {
     tat[i]=bt[i]+wt[i];
    }
 int avgtat=0;
    printf("\nProcess\tBT\tWT\tTAT");
    for(i=0;i<n;i++)
    {
    printf("\nP-%d\t%d\t%d\t%d",pid[i],bt[i],wt[i],tat[i]);
    avgwt=avgwt+wt[i];
     avgtat=avgtat+tat[i];
    }
    avgtat=avgtat/n;
    printf("\n\nAverage Turn Around Time= %d",avgtat);
}
