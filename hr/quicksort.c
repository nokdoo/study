void intquick(int *x, int left, int right){
    int tmp;
    if(left < right){
		int p = left, i = left, j = left+1;
		while(j <= right){
			if(x[p] > x[j]){
                tmp = x[++i];
                x[i] = x[j];
                x[j] = tmp;
			}
			j++;
		}
		tmp = x[p];
        x[p] = x[i];
        x[i] = tmp;
		intquick(x, left, i-1);
		intquick(x, i+1, right);
	}
}
