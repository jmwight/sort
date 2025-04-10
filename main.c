#include "core/sort.h"
#include "readwritelines/readwritelines.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXLINE		256
#define MAXLINES	5120
#define MEMSIZE		128000

#define STD_ORDER	0
#define	NUM_ORDER	1
#define DIR_ORDER	2

char *lineptr[MAXLINES];
char linemem[MEMSIZE];

int numcmp(char *, char *);
int dircmp(char *, char *);
int dircasecmp(char *, char *);


int main(int argc, char **argv)
{
	/* process user inputs */
	int nlines;	/* number of input lines read */
	int order, reverse, ignore_case;
	reverse = ignore_case = 0; /* 0 is false */
	order = STD_ORDER; 
	
	/* get arguments */
	while(--argc > 0)
	{
		++argv;
		do
		{
			if(**argv == 'n')
				order = NUM_ORDER;
			else if(**argv == 'r')
				reverse = 1; /* 1 is true */
			else if(**argv == 'f')
				ignore_case = 1;
			else if(**argv == 'd')
				order = DIR_ORDER;

		} while(*(*argv)++ != '\0');

	}
	
	/* we can't have both ignore_case and numeric true */
	if(order == NUM_ORDER && ignore_case)
	{
		printf("Usage: can't have ignore case and numeric sort.\n");
		return -1;
	}

	/* get lines, sort them and print sorted result */
	if((nlines = readlines(lineptr, linemem, MEMSIZE, MAXLINES, MAXLINE)) >= 0)
	{
		/* find what comparison function we are using */
		void *func;
		if(order == STD_ORDER)
			func = numcmp;
		else if(order == STD_ORDER && ignore_case)
			func = strcasecmp;
		else if(order == DIR_ORDER)
		{
			if(!ignore_case)
				func = dircmp;
			else
				func = dircasecmp;
		}
		else
			func = strcmp;

		qsort2((void **) lineptr, 0, nlines - 1, (int (*)(void*, void*))(func), reverse);
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

/* dircmp: directory compare. returns difference only counting letters, blanks, and numbers */
int dircmp(char *s1, char *s2)
{
	int s1l, s2l;
	s1l = s2l = 0;
	/* get total for s1 only counting blanks, letters, and numbers and ignoring all else */
	while(*s1 != '\0')
	{
		if(*s1 >= 'A' && *s1 <= 'Z' || *s1 >= 'a' && *s1 <= 'z' || *s1 >= '0' && *s1 <= '9' || *s1 == ' ' || *s1 == '\t' 
				|| *s1 == '\n' || *s1 == '\r' || *s1 == '\v' || *s1 == '\f')
			s1l += *s1;
		s1++;
	}

	while(*s2 != '\0')
	{
		if(*s2 >= 'A' && *s2 <= 'Z' || *s2 >= 'a' && *s2 <= 'z' || *s2 >= '0' && *s2 <= '9' || *s2 == ' ' || *s2 == '\t' 
				|| *s2 == '\n' || *s2 == '\r' || *s2 == '\v' || *s2 == '\f')
			s2l += *s2;
		s2++;
	}

	return s1l - s2l;
}

/* dircmp: directory compare. returns difference only counting letters, blanks, and numbers but ignoring case */
int dircasecmp(char *s1, char *s2)
{
	int s1l, s2l;
	s1l = s2l = 0;
	/* get total for s1 only counting blanks, letters, and numbers and ignoring all else */
	while(*s1 != '\0')
	{
		if(*s1 >= 'A' && *s1 <= 'Z' || *s1 >= 'a' && *s1 <= 'z' || *s1 >= '0' && *s1 <= '9' || *s1 == ' ' || *s1 == '\t' 
				|| *s1 == '\n' || *s1 == '\r' || *s1 == '\v' || *s1 == '\f')
			if(*s1 >= 'a' && *s1 <= 'z') /* convert to upper if it's lower for counting purposes */
			{
				s1l += *s1 + 'A' - 'a';
			}
			else
				s1l += *s1;
		s1++;
	}

	while(*s2 != '\0')
	{
		if(*s2 >= 'A' && *s2 <= 'Z' || *s2 >= 'a' && *s2 <= 'z' || *s2 >= '0' && *s2 <= '9' || *s2 == ' ' || *s2 == '\t' 
				|| *s2 == '\n' || *s2 == '\r' || *s2 == '\v' || *s2 == '\f')
			if(*s2 >= 'a' && *s2 <= 'z') /* convert to upper if it's lower for counting purposes */
			{
				s2l += *s2 + 'A' - 'a';
			}
			else
				s2l += *s2;

		s2++;
	}

	return s1l - s2l;
}
