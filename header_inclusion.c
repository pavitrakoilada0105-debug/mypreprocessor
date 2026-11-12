#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"preprocessor.h"

int header_inclusion(char *line,FILE *out)
{
FILE *fp;
char filename[100];  
char path[300];
char temp[1000];
int i=0,j=0;

while(line[i]!='"' && line[i]!='<' && line[i]!='\0')
  i++;

if(line[i]=='\0')
  return 1;

char end;
if(line[i]=='<')
  end='>';
else
  end='"';
i++;

while(line[i]!=end && line[i]!='\0' && j<99)
 filename[j++]=line[i++];

filename[j]='\0';

if(line[i]!=end)
  return 1;

fp=fopen(filename,"r");
  if(fp=NULL && end=='>')
  {
    char *paths[]=
    {
    "/usr/lib/gcc/x86_64-linux-gnu/7/include/",
    "/usr/local/include/",
    "/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed/",
    "/usr/include/"
    };

   for(i=0;i<5;i++)
     {
      strcpy(path,paths[i]);
       strcat(path,filename);

       fp=fopen(path,"r");

       if(fp!=NULL)
         break;
     }
  }
if(fp==NULL)
{
printf("header file not found: %s\n",filename);
return 1;  
}

while(fgets(temp,sizeof(temp),fp)!=NULL)
  fputs(temp,out);

fclose(fp);

return 0;  
}

void file_inclusion(FILE *fp,FILE *out)
{
FILE *temp;
char line[1000];

temp=fopen("temp.c","w");

while(fgets(line,sizeof(line),fp)!=NULL)
  {
   if(strncmp(line,"include",8)==0)
   header_inclusion(line,temp);
   else
     fputs(line,temp);
  }

  fclose(temp);
  temp=fopen("temp.c","r");

  if(temp==NULL)
  {
   printf("cannot open temp.c\n");
    return;
  }

  printf("reading temp.c\n");
  remove_comments(temp,out);

  fclose(temp);
}
