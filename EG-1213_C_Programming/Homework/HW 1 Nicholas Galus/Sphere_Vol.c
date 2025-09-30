#include <stdio.h>

int main(void)
{
	float radius;
	float vol;
	
	printf("Enter the radius of a sphere: ");
	scanf("%f", &radius);
	
	vol = ((4.0f/3.0f) * (3.1415) * radius * radius * radius);
	
	printf("The volume of the sphere is: %f\n", vol);
	
	return 0;
}