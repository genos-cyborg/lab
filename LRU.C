/*Program for LRU Page replacement simulation*/

#include<stdio.h>

struct node
{
  	int pno,reftime;
}frames[20];

int n;

int pg_found(int pno)
{
  	int fno;
  	
	for(fno=0;fno<n;fno++)
  	{
  		if(frames[fno].pno==pno)
  		{
	   		return fno;
		}
	}
	
	return -1;
}

int get_free_frame()
{  
	int fno;
  	
	for (fno=0; fno<=n; fno++)
  	{
		if (frames[fno].pno==-1)
		{
			return(fno);
		}
	}
   	
	return(-1);
}

int get_lru_frame()
{
  	int fno;
  	int selfno=0;
  
  	for (fno=1; fno<n; fno++)
  	{
  		if(frames[fno].reftime<frames[selfno].reftime)
  		{
			selfno=fno;
		}
	}
	
  	return selfno;
}

int main()
{
   	int p_req[]={5,8,10,14,10,9,5,10,8,5,1,10,9,12,10};
   	int size=15,currtime;
   	int pg_faults=0,i,j,fno;
  
   	printf("\nHow many frames:");  
   	scanf("%d",&n);
   
   	for (i=0; i<n; i++)
   	{ 
	   	frames[i].pno=-1;
	 	frames[i].reftime=-1;
   	}

   	printf("\nPageNo     Page Frames          Page Fault");
   	printf("\n-------------------------------------------");
   
   	currtime=0;
   
   	for(i=0;i<size;i++)
   	{
	 	j=pg_found(p_req[i]);

	 	if(j==-1) 
	 	{
	   		j=get_free_frame();
	   		
			if (j==-1) 
			{
				j=get_lru_frame();
			}
	   		
			pg_faults++;
		   
		   	frames[j].pno=p_req[i];
		   	frames[j].reftime=currtime;
		   
		   	printf("\n%4d\t ",p_req[i]);
		   	
			for (fno=0; fno<n; fno++)
			{
				printf("%4d",frames[fno].pno);
			}
		   	
			printf(" : F");
	 	}
		else
		{
			frames[j].pno=p_req[i];
		   	frames[j].reftime=currtime;
		   	
			printf("\n%4d\t ",p_req[i]);
		   	
		   	for (fno=0; fno<n; fno++)
			{
			 	printf("%4d",frames[fno].pno);
			}
		   	printf(" : H");
		}
		
	   	currtime++;
   	}
   	
  	printf("\n------------------------------------------");
  	printf("\n Number of Page Faults = %d",pg_faults);

}
