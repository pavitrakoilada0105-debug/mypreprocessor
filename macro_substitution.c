#include<stddio.h>
#include<string.h>
#include"preprocessor.h"

struct macro
{
char name[50];
char value[200];
};

struct macro m[100];
int count=0;

void macro_substitution(FILE *fp,FILE *out)
{
char line[1000];
char word[50];
int i,j,k,found;

while(fgets(line,sizeof(line),fp)!=NULL)
  {
    if(strncmp(line,"#define",7)==0)
    {
      i=7;
      while(line[i]==' ' || line[i]=='\t')
        i++;
      j=0;
      while(line[i]!=' ' && line[i]!='\t' && line[i]!='\n' && line[i]!='\0')
        {
         m[count].name[j++]=line[i++];
        }
      m[count].name[j]='\0';
      while(line[i]==' ' || line[i]=='\t')
        i++;
      strcpy(m[count].value,line+i);
      m[count].value[strcspn(m[count].value,"\n")]='\0';
      count++;
    }
    else
    {
      i=0;
       while(line[i]!='\0')
         {
           j=0;
           while((line[i]>='A' && line[i]<='Z') || (line[i]>='a' && line[i]<='z') || (line[i]>='0' && line[i]<='9') || line[i]=='_')
             {
                   if(j<49)
                       word[j++]=line[i];
                   i++;
             }
           word[j]='\0';

           if(j>0)
           {
              found=0;
              for(k=0;k<count;k++)
                {
                  if(strcmp(word,m[k].name)==0)
                  {
                    fputs(m[k].valur,out);
                     found=1;
                     break;
                  }
                }
             if(found==0)
               fputs(word,out);
           }
           else
           {
             fputc(line[i],out);
              i++;
           }
         }
    }
  }
}
