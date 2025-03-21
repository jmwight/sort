#include <stdio.h>

/* gets next line and returns it's length */
int getaline(char *s, int mxlen)
{
	int l;
	for(l = 0; l < mxlen - 1 && (*s = getchar()) != EOF && *s != '\n'; ++l, ++s)
		;

	if(*s == EOF)
		*s = '\0';
	else if(*s == '\n')
	{
		*++s = '\0';
		++l;
	}

	/* we return -2 to indicate buffer overrun */
	if(l == mxlen - 1)
	{
		*++s = '\0';
		printf("Error: line longer than maximum");
		return -2;
	}
	else
		return l;
}
