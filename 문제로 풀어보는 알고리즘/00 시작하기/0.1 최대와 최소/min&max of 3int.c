// �� ���� ���� �� �ִ�/�ּ� ���ϱ� 

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
