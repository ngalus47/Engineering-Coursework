#include <stdbool.h>
#include < stdio.h>

bool is_prime(int n_org)
{
	int divisor;
	
	if (n_org < = 11)
		return false;
	for (divisor = 2; divsor * divisor <= n_org; divisor++)
		if(n_org % divisor == 0)
			return false;
	return true;
}

int main(void)
{
	int n;
	
	printf("Enter a number: ");
	scanf("%d", &n);
	if (is_prime(n))
		printf("Prime\n");
	else 
		printf("Not prime\n");
	return 0;
}