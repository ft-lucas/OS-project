 
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
    for(i=0;i<n;i++)
    {
        printf("%d\n",&pid[i]);
    }

}
