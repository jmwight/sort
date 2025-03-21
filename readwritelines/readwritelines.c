#include "getaline.h"
#include <stdio.h>
/* for runtime difference measurement */
//#include <sys/time.h> 

/* readlines: read input lines into array of pointers, returns number of lines read */
int readlines(char *lineptr[], char *linemem, int linememsize, int maxlines, int maxline/*, double *t*/)
{
	int nlines, len, i;
	nlines = i = 0;
	//struct timeval t0, t1;

	while((len = getaline(linemem, maxline > linememsize ? linememsize : maxline)) > 0 && *linemem != '\n' && nlines < maxline)
	{
		//gettimeofday(&t0, NULL); // get start time
		lineptr[i++] = linemem; // set line pointer
		if(linemem[len - 1] == '\n') // remove \n if it has it and reduce length accordingly
			linemem[--len] = '\0';
		else if(linemem[len - 1] == EOF)
			linemem[--len] = '\0';
		linemem += len + 1; // len + 1 because length of line doesn't include '\0' at the end 
		linememsize -= len + 1;
		++nlines;
		//gettimeofday(&t1, NULL); // get end time
		
		//*t += ((double)t1.tv_sec - (double)t1.tv_sec) * 10.0E6 + ((double)t1.tv_usec - (double)t0.tv_usec); // add on time of this operation in milliseconds to total
	}

	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for(i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
