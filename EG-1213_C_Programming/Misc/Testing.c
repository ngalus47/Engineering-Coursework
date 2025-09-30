#include <stdio.h> // Include the standard I/O library

int main() {
	
	//Chapter 4 question 5
	printf("%d \n", 8 % 5);
	printf("%d \n", -8 % 5);
	printf("%d \n", 8 % -5);
	printf("%d \n", -8 % -5);
	
	int i, j, k;
	
	//Chapter 4 questtion 11
	i = 5;
	printf("%d ", i++ - 1);
	printf("%d \n", i);
	
	i = 10; j =5;
	printf("%d ", i++ - ++j);
	printf("%d %d \n", i, j);
	
	i = 7; j = 8;
	printf(%d ", i++ - --j);
	printf(%d %d \n", i, j);

	i = 3; j = 4; k = 5;
	printf("%d ", i++ - j++ + --k);
	printf("%d %d %d \n", i, j, k);
	
	//Chapter 4 question 12
	i = 5;
	j = ++i * 3-2;
	printf("%d %d \n", i, j);
	
	i = 5;
	j = 3 - 2 * i++;
	printf("%d %d \n", i, j);
	
	i = 7;
	j = 3 * i-- * 2;
	printf("%d %d \n", i, j);
	
	i = 7;
	j = 3 + --i * 2;
	printf("%d %d \n", i, j);
	
	//Chapter 5 question 1
	i = 2; j = 3;
	k = i * j == 6;
	printf("%d \n", k);
	
	i = 5; j = 10; k = 1;
	printf("%d \n", k > i < j);
	
	i = 3; j = 2; k = 1;
	printf("%d \n", i < j == j < k);
	
	i = 3; j = 4; k = 5;
	printf("%d", i % j + i < k);
	
	//Chapter 5 question 4
	
	
    return 0;
}