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
void turnartime(int ar[],int ar2[],int tat[],int n)
{
	printf("\n\nCalulating the turn around time for every process");
	int i;
for(i=0;i<n;i++)
    {
     tat[i]=ar[i]+ar2[i];
	}
	return(tat);
}
/*  
number of process n<=20;
*/
int main()
{
    int pid[20];  //process id
    int bt[20];   //burst time
    int wt[20];   //waiting time
    int tat[20];  //turn around time
    int n,i,j;
    
    printf("Enter No. of process");
    scanf("%d",&n);
    
    printf("Enter the Process Id in proper sequence: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
    }
    printf("Enter the Burst Time in proper sequence: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    waitingtime(wt,bt,n);
    
	turnartime(wt,bt,tat,n);
	
 float avgtat=0;
    printf("\nProcess\tBT\tWT\tTAT");
    for(i=0;i<n;i++)
    {
    printf("\nP-%d\t%d\t%d\t%d",pid[i],bt[i],wt[i],tat[i]);
    
     avgtat=avgtat+tat[i];
    }
    avgtat=avgtat/n;
    printf("\n\nAverage Turn Around Time= %f",avgtat);
 
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
     
}
     for(i=0;i<n;i++){
wt[i]=0;
}

  waitingtime(wt,bt,n);
     turnartime(wt,bt,tat,n);
	
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
