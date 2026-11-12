mypreprocessor: main.o comment_remove.o header_inclusion.o macro_substitution.o
          gcc main.o comment_remove.o header_inclusion.o macro_substitution.o -o mypreprocessor
main.o:main.c
     gcc -c main.c
comment_remove.o:comment_remove.c
     gcc -c comment_remove.c
header_inclusion.o:header_inclusion.c
     gcc -c  header_inclusion.c
macro_substitution.o:macro_substitution.c
     gcc -c macro_substitution.c

clean: 
     rm -f *.o mypreprocessor
