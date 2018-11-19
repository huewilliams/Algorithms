int max_arr(int arr[], int arrlen)
{
	int max, i;
	
	max = arr[0];
	for (i=0; i<arrlen; i++)
		if(arr[i] > max)
			max = arr[i];
	return max;
}

int min_arr(int arr[], int arrlen)
{
	int min, i;
	for(i=0;i<arrlen;i++)
		if(arr[i] < min)
			min = arr[i];
	return min;
}
