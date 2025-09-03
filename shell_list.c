#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <dirent.h>

char comm[100],*ptr;
char *args[10];
int tot_arg;

void getcomm();
void sep_arg();
void take_action();
		
void list( char, char[]);

int main()
{
	while(1)
	{
		printf("MyShell$ ");
		getcomm();
		sep_arg();
		take_action();
	}
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

	if(strcmp(args[0],"list") == 0 )
		list(args[1][0],args[2]);
	else if(strcmp(args[0],"quit") == 0 )
		exit(0);		
}

void list( char option, char dirname[])
{
	DIR *dp;
	struct dirent *dent;
	int cnt=0;
	
	chdir(dirname);
	
	switch(option)
	{
		case 'f' : // list all dir entries
				dp= opendir(".");
				if( dp == NULL )
				{
					printf("\n Unable to open dir");
					exit(0);
				}
	
				while( dent = readdir(dp) )
				{
					printf("\n%s",dent->d_name);
				}
				printf("\n");
				break;
		case 'n' : // list number all dir entries
				cnt =0;
				dp= opendir(".");
				if( dp == NULL )
				{
					printf("\n Unable to open dir");
					exit(0);
				}
				while( dent = readdir(dp) )
				{
					cnt++;
				}
				printf("\ntot dir entries = %d\n",cnt);
				closedir(dp);
				break;
		case 'i' : // list all dir entries with inode
				dp= opendir(".");
				if( dp == NULL )
				{
					printf("\n Unable to open dir");
					exit(0);
				}
	
				while(dent = readdir(dp))
				{
					printf("\n%s %ld",dent->d_name,dent->d_ino);
	
				}
				closedir(dp);
				break;
		default :	printf("\nInvalid option");
				exit(0);
	} 
}


