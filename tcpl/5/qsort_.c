void qsort_(void *v[], int left, int right,
		int (*comp)(void *, void *), int reverse){
	int i, last;
	void swap(void *v[], int, int);

	if(left >= right)
		return;

	swap(v, left, (left + right)/2);
	last = left;
	for(i = left + 1; i <= right; i++){
		if((*comp)(v[i], v[left])*reverse < 0)
			swap(v, ++last, i);
	}

	swap(v, left, last);
	qsort_(v, left, last-1, comp, reverse);
	qsort_(v, last+1, right, comp, reverse);
}
