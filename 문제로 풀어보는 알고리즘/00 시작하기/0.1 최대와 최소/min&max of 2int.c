// 최대 값과 최소 값을 구하는 함수 

int min(int x , int y)
{
	if(x < y)
		return y;
	return x; 
}

int max(int x, int y)
{
	if(x > y)
		return x;
	return y;
}
