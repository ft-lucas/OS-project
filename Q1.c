   void waitingtime(int ar[],int ar2[],int n)
    {
    	int i,j;
    	ar[0]=0;
    printf("\n\nCalulating the waiting time for every process");
    for(i=1;i<n;i++)
    {
      ar[i]=0;
      for(j=0;j<i;j++)
      {
       ar[i]=ar[i]+ar2[j];
      }
    }
    return(ar);
	}

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
    waitingtime(wt,bt,n);
    printf("\n\nCalulating the turn around time for every process");
    for(i=0;i<n;i++)
    {
     tat[i]=bt[i]+wt[i];
    }
 float avgtat=0;
    printf("\nProcess\tBT\tWT\tTAT");
    for(i=0;i<n;i++)
    {
    printf("\nP-%d\t%d\t%d\t%d",pid[i],bt[i],wt[i],tat[i]);
    
     avgtat=avgtat+tat[i];
    }
    avgtat=avgtat/n;
    printf("\n\nAverage Turn Around Time= %d",avgtat);
 
    printf("\n\nSolution using SHORTEST JOB FIRST: ");
    //waitingtime(wt);
    printf("\n Sorting the processes ");
 int temp;   
 for(i=0;i<n;i++)
    {
     for(j=0;j<n-i-1;j++)
     {
     if(bt[j]>bt[j+1])
     {
     temp=bt[j+1];
      bt[j+1]=bt[j];
      bt[j]=temp;
     }
     }
     for(i=0;i<n;i++){
 printf("%d",bt[i]);
}
}
     for(i=0;i<n;i++){
wt[i]=0;
}

  waitingtime(wt,bt,n);
     for(i=0;i<n;i++){
 printf("%d",wt[i]);
}
printf("\n\nCalulating the turn around time for every process");
    for(i=0;i<n;i++)
    {
     tat[i]=bt[i]+wt[i];
    }
    avgtat=0;
    printf("\nProcess\tBT\tWT\tTAT");
    for(i=0;i<n;i++)
    {
    printf("\nP-%d\t%d\t%d\t%d",pid[i],bt[i],wt[i],tat[i]);
    
     avgtat=avgtat+tat[i];
    }
    avgtat=avgtat/n;
    printf("\n\nAverage Turn Around Time= %f",avgtat);
}
