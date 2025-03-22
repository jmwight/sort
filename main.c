#include "core/sort.h"
#include "readwritelines/readwritelines.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXLINE		256
#define MAXLINES	5120
#define MEMSIZE		128000
char *lineptr[MAXLINES];
char linemem[MEMSIZE];

int numcmp(char *, char *);

int main(int argc, char **argv)
{
	/* process user inputs */
	int nlines;	/* number of input lines read */
	int numeric, reverse;
	numeric = reverse = 0; /* 1 if numeric sort */
	
	/* get arguments */
	while(--argc > 0)
	{
		++argv;
		do
		{
			if(**argv == 'n')
				numeric = 1;
			else if(**argv == 'r')
				reverse = 1;
		} while(*(*argv)++ != '\0');

	}

	/* get lines, sort them and print sorted result */
	if((nlines = readlines(lineptr, linemem, MEMSIZE, MAXLINES, MAXLINE)) >= 0)
	{
		qsort2((void **) lineptr, 0, nlines - 1, (int (*)(void*, void*))(numeric ? numcmp : strcmp), reverse);
		printf("\n\nSorted Lines:\n");
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
	}
}

int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if(v1 < v2)
		return -1;
	else if(v1 > v2)
		return 1;
	else
		return 0;
}
