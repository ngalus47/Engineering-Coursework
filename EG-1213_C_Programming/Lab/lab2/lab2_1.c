#include <stdio.h>

int main(void)
{
	char line1[] = "N   N     M   M      GG\n";
	char line2[] = "N   N     M   M     G  G\n";
	char line3[] = "NN  N     MM MM     G\n";
	char line4[] = "N N N     M M M     G GGG\n";
	char line5[] = "N  NN     M   M     G  G\n";
	char line6[] = "N   N     M   M     G  G\n";
	char line7[] = "N   N     M   M      GG\n";

	printf("%s%s%s%s%s%s%s\n", line1, line2, line3, line4, line5, line6, line7);

	return 0;
}