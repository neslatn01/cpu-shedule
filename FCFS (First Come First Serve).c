#include<stdio.h>
void main()
{
	int i=0,j=0,b[i],g[20],p[20],w[20],t[20],a[20],n=0,m;
	float avgw=0,avgt=0;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Process ID : ");
		scanf("%d",&p[i]);
		
		printf("Burst Time : ");
		scanf("%d",&b[i]);

		printf("Arrival Time: ");
		scanf("%d",&a[i]);
	}
	
	int temp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;

				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;

				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	
	g[0]=0;
	for(i=0;i<=n;i++)
		g[i+1]=g[i]+b[i];
	for(i=0;i<n;i++)
	{
		
		t[i]=g[i+1]-a[i];
		w[i]=t[i]-b[i];
		avgw+=w[i];
		avgt+=t[i];
	}
	avgw=avgw/n;
	avgt=avgt/n;
printf("pid\tarrivalT\tBrustT\tCompletionT\tWaitingtime\tTurnaroundTi\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t\t%d\t\t\t%d\n",p[i],a[i],b[i],g[i+1],w[i],t[i]);
	}
	printf("\nAverage waiting time %f",avgw);
	printf("\nAverage turnarround time %f",avgt);
}
