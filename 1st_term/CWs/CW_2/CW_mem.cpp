Decimal* div10 (const Decimal* a)
{
	int sz = a->n;
	Decimal* ans = malloc(sizeof(char) * sz + sizeof(int) * 2);
	
	if ( sz ) 
		ans->n = sz - 1;
	else
	{
		ans->a[0] = '0';
		ans->n = 0;
		return ans;
	}
	
	ans->a = malloc(sizeof(char) * sz);
	
	for (int i = 0; i < sz; i++)
		ans->a[i] = a->a[i+1];
	
	return ans;
}
