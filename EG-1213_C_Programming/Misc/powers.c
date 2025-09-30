#include <stdio.h>

int power(int n, int power)
{
	int result;
	
	switch(n)
	{
		n % 2 == 0: result = (n * (power / 2)) * (n * (power / 2); break;
		n % 2 == 1: result += (n * n) + power(n, --power); break;
	}
	
	return result;
}

int Main(void)
{
	int number, power;
	
	printf("Enter a number: ");
	scanf("%d", &number);
	
	printf("Enter a power: ");
	scanf("%d", &power);
	
	printf("Result %d", power(number, power));
}
