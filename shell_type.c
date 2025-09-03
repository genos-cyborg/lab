#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

char comm[100],*ptr;
char *args[10];
int tot_arg;

void getcomm();
void sep_arg();
void take_action();
		
void typeline(char[], char[]);

int main()
{
	while(1)
	{
		printf("\n MyShell$ ");
		getcomm();
		sep_arg();
		take_action();
	}
	
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
	
	args[tot_arg][j] = '\0'; 
}

void take_action()
{
	char str[100];

	if(strcmp(args[0],"typeline") == 0 )
		typeline(args[1],args[2]);
	else if(strcmp(args[0],"quit") == 0 )
		exit(0);		
}

void typeline( char option[], char fname[])
{
	FILE *fp;
	int tot_lines=0,ch,n,cnt;
	
	fp= fopen(fname,"r");
	
	if( fp == NULL )
	{
		printf("\n Unable to open file");
	}
	else
	{
		while ( ch != EOF )
		{
			ch = fgetc(fp);
			
			if(ch == '\n') 
				tot_lines++;
		}
		fclose(fp);
		
		if(strcmp(option,"a")== 0) // print all lines
		{
			fp = fopen(fname,"r");
			
			while (ch != EOF)
			{
				ch = fgetc(fp);
				printf("%c",ch);
			}
			fclose(fp);
		}
		else if(option[0] == '+') //print first n lines)
		{
			n = atoi(option+1);
			if(n > tot_lines)
			{	
				printf("\n Invalid  option");
			}
			else
			{
				fp= fopen(fname,"r");
				
				cnt = 0;
				while( cnt < n )
				{
					ch = fgetc(fp);
					printf("%c",ch);
					if(ch == '\n')
						cnt++;
				}
				fclose(fp);
			}
		}
		else if(option[0] =='-') //print last  n lines)
		{
			n = atoi(option+1);
			
			if(n > tot_lines)
			{	
				printf("\n Invalid option");
			}
			else
			{
				fp= fopen(fname,"r");
				cnt = 0;
				while(cnt < tot_lines-n)
				{
					ch = fgetc(fp);
					if(ch == '\n')
						cnt++;
				}
				while( (ch=fgetc(fp)) != EOF )
				{
					printf("%c",ch);	
				}
				fclose(fp);
			}
		}
		else
		{
			printf("\n Invalid option");
		}
	}
}


