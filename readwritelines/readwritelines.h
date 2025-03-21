#ifndef READWRITELINES_H
#define READWRITELINES_H	1

int readlines(char **lineptr, char *linemem, int linememsize, int maxlines, int maxline/*, double *milliseconds*/);
void writelines(char **lineptr, int nlines);

#endif
