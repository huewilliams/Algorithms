// 세 개의 정수 중 최대/최소 구하기 

int max(int x, int y, int z)
{
	if(x > y && x > z)
		return x;
	else if(y > x && y > z)
		return y;
	return z;
}

int min(int x, int y, int z)
{
	if(x < y && x < z)
		return x;
	else if(y < x && y < z)
		return y;
	return z;
}
