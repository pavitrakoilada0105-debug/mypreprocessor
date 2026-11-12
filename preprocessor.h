#ifndef PREPROOCESSOR_H
#define PREPROCESSOR_H

#include<stdio.h>
#include<stddef.h>

void remove_comments(FILE *fp,FILE *fp1);

int header_inclusion(char *line,FILE *out);

void file_inclusion(FILE *fp,FILE *out);

void macro_substitution(FILE *fp,FILE *out);

#endif
