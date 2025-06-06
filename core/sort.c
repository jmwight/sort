void swap(void **, int, int);

/* qsort: sort v[left]...v[right] into increasing order */
void qsort2(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
	int i, last;
	//void swap(void *v[], int, int);

	if(left >= right) /* do nothing if array contains */
		return;	  /* fewer than two elements */

	swap(v, left, (left+right)/2);
	last = left;
	for(i = left+1; i <= right; i++)
	{
		if(reverse == 0)
		{
			if((*comp)(v[i], v[left]) < 0)
				swap(v, ++last, i);
		}
		else
		{
			if((*comp)(v[i], v[left]) > 0)
				swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort2(v, left, last-1, comp, reverse);
	qsort2(v, last+1, right, comp, reverse);
}

void swap(void *v[], int x, int y)
{
	void *tmp = v[x];
	v[x] = v[y];
	v[y] = tmp;
}
