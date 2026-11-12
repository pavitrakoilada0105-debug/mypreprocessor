#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"preprocessor.h"
int main(int argc,char *argv[])
{
if(argc!=2)
{
printf("Usage: ./mypreprocessor inputfile.c\n");
  return 1;
}

  FILE *fp,*fp1;
  char output[256];
  int ch;
  char *dot;

  fp=fopenn(argv[1],"r");
  if(fp==NULL)
  {
   printf("Unable to open file\n");
    return 1;
  }

  if(strlen(argv[1])>=sizeof(output)-3)
  {
    printf("Filename too long\n");
    fclose(fp);
    return 1;
  }

  strcpy(output,argv[1]);
  dot(strrchr(output,'.');

  if(dot!=NULL)
    strcpy(cot,".i");
  else
    strcat(output,".i");

  fp1=fopen(output,"w');

    if(fp1=NULL)
    {
      printf("unable to create output file\n");
       fclose(fp);
       return 1;
    }
FILE *temp;
temp=fopen("temp2.c","w");
file_inclusion(fp,temp);
fclose(temp);
temp=fopen("temp2.c","r");
macro_substitution(temp,fp1);
fclose(temp);
remove("temp2.c");
printf("output file created:%s\n",output);

fclose(fp);
fclose(fp1);
return 0;
}
