#include <stdio.h>

int main(void)
{
	int xInt, ans;
	
	printf("Enter a value for X: ");
	scanf("%d", &xInt);
	
	ans = (3 * (xInt * xInt * xInt * xInt * xInt));
	ans += (2 * (xInt * xInt * xInt * xInt));
	ans -= (5 * (xInt * xInt * xInt));
	ans -= (xInt * xInt);
	ans += ((7 * xInt) - 6);
	
	printf("Answer: %d\n", ans);
}