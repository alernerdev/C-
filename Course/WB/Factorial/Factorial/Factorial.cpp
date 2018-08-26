int Factorial(int n)
{
	if (n == 0)
		return 1;
	else if (n < 0)
		return 1;

	int fact = 1;
	for (int i = 2; i <= n; i++)
	{
		fact *= i;
	}

	return fact;
}