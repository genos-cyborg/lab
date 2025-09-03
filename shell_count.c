//EXTENDED SHELL ---COUNT

#include<stdio.h>
#include<sys/types.h> 
#include<sys/stat.h>
#include<malloc.h>
#include<stdlib.h>

char comm[100],*ptr;
char *args[10];
int tot_arg;

void count( char option, char *fname)// count c/w/l   <filename>
{
	int ch,i,ccnt,wcnt,lcnt;
	FILE *fp;
	
	fp= fopen(fname,"r");
	
	if( fp == NULL )
	 {
		printf("\nUnable to open file");
		return;
	}
	ccnt =wcnt = lcnt = 0;
	ch = fgetc(fp);
	while(ch != EOF)
	{
		ccnt++;
		
		if(ch ==' ' || ch== '\t')
		{
			wcnt++;	
		}
		else if( ch == '\n')
		{
			lcnt++;
			wcnt++;	
		}
		
		ch = fgetc(fp);
	}
	
	fclose(fp);
	
	switch(option)
	{
	case 'c' : // print all chars 
			printf("\nTot chars = %d\n",ccnt);
			break;
	case 'w' : // print all words 
			printf("\nTot words = %d\n",wcnt);
			break;
	case 'l' : // print all lines 
			printf("\nTot lines = %d\n",lcnt);
			break;
	} 
}
int main()
{
	do
	{
		printf("myshell $ ");
		getcomm();
		sep_arg();
		take_action();
	}while(1);
	
	return 0;
} 

void getcomm()
{
	int len;
	fgets(comm,80,stdin);
	len = strlen(comm);
	comm[len-1] = '\0';
} 

void sep_arg()
{
	int i,j;
	i = j = tot_arg = 0;

	args[tot_arg] = (char*)malloc(sizeof(char) * 20);
	
	for(i=0; comm[i] !='\0';i++)
	{
		if(comm[i] == ' ')
		{
			args[tot_arg][j] = '\0';
			tot_arg++;
			args[tot_arg] = (char*)malloc(sizeof(char) * 20);	
			j=0;
		}
		else
		{
			args[tot_arg][j] = comm[i];
			j++;
		}
	} 
	
	args[tot_arg][j] = '\0'; // complete last word
}

void take_action()
{
	char str[100];
	pid_t pid;
	int status;

	if(strcmp(args[0],"count") == 0 )
		count(*args[1],args[2]);
	else if(strcmp(args[0],"quit") == 0 )
		exit(0);		
}

