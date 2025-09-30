#include <stdio.h>

int main(void)
{
	int dllrAmt;
	
	printf("Enter a dollar amount: ");
	scanf("%d", &dllrAmt);
	
	printf("\n$20 bills: %d\n", dllrAmt / 20);
	dllrAmt %= 20;
	
	printf("$10 bills: %d\n", dllrAmt / 10);
	dllrAmt %= 10;
	
	printf(" $5 bills: %d\n", dllrAmt / 5);
	dllrAmt %= 5;
	
	printf(" $1 bills: %d\n", dllrAmt / 1);
	
	return 0;
}