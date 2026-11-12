#include<stdio.h>
#include"preprocesser.h"
void remove_comments(FILE *fp,FILE *fp1)
{
int ch,next,prev;
while((ch=fgetc(fp))!=EOF)
{  
if(ch=='/')
{
next=fgetc(fp);
  if(next=='/')
  {
   while((ch=fgetc(fp))!=EOF && ch!='\n');
   if(ch=='\n')
     fputc('\n',fp1);
  }
  else if(next=='*')
  {
    prev=0;
    while((ch=fgetc(fp))!=EOF)
      {
       if(ch=='\n')
         fputc('\n',fp1);
        if(prev=='*' && ch=='/')
          break;
        prev=ch;
      }
  }
  else
  {
   fputc('/',fp1);
    if(next!=EOF)
       fputc(next,fp1);
  }
}
  else
{
fputc(ch,fp1);
}
}
}
